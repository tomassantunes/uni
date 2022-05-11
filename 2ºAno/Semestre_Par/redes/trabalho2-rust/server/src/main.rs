use std::io::{ErrorKind, Read, Write};
use std::net::TcpListener;
use std::os::unix::io::AsRawFd;
use std::sync::mpsc;
use std::sync::mpsc::Sender;
use std::thread;

const LOCAL: &str = "127.0.0.1:1234";
const MSG_SIZE: usize = 256;
static mut NICKS: Vec<(i32, String)> = Vec::new();

fn sleep() {
    thread::sleep(::std::time::Duration::from_millis(100));
}

fn process_msg(msg: String, fd: i32, tx: Sender<String>) { 
    let chunks: Vec<&str> = msg.split(' ').collect();

    if chunks[0] == "HELLO" {
        unsafe {
            let mut exists = false;
            for x in NICKS.clone() {
                if x.1 == chunks[1].to_string() { exists = true; }
            }
            if !exists {
                NICKS.push((fd, chunks[1].to_string()));
            } else {
                let msg = format!("ERR NICK {}", chunks[1].to_string());
                tx.send(msg).expect("Failed to send message to rx.");
            }
        }
    }

    let joined = chunks[1..].join(" ");
    println!("default msg: {:?}.", joined);

    unsafe{ println!("NICKS: {:?}.", NICKS); }
}

fn main() {
    let server = TcpListener::bind(LOCAL).expect("Listener failed to bind.");
    server.set_nonblocking(true).expect("Failed to initialize non-blocking.");

    let mut clients = vec![];
    let (tx, rx) = mpsc::channel::<String>();

    loop {
        if let Ok((mut socket, addr)) = server.accept() {
            println!("Client {:?} connected", addr);

            let tx = tx.clone();
            clients.push(socket.try_clone().expect("Failed to clone client."));

            thread::spawn(move || loop {
                let mut buff = vec![0; MSG_SIZE];
                
                match socket.read_exact(&mut buff) {
                    Ok(_) => {
                        let msg = buff.into_iter().take_while(|&x| x != 0).collect::<Vec<_>>();
                        let msg = String::from_utf8(msg).expect("Invalid utf8 message.");

                        process_msg(msg.clone(), socket.as_raw_fd(), tx.clone());

                        tx.send(msg).expect("Failed to send message to rx.");
                    },
                    Err(ref err) if err.kind() == ErrorKind::WouldBlock => (),
                    Err(_) => {
                        let mut disc_user: String = String::new();
                        unsafe {
                            for x in NICKS.clone() {
                                if x.0 == socket.as_raw_fd() {
                                    disc_user = x.1;
                                }
                            }
                        }

                        println!("Closing connection with {}.", disc_user);
                        break;
                    }
                }

                sleep();
            });
        }
        
        if let Ok(msg) = rx.try_recv() {
            clients = clients.into_iter().filter_map(|mut client| {
                let mut buff = msg.clone().into_bytes();
                buff.resize(MSG_SIZE, 0);

                client.write_all(&buff).map(|_| client).ok()
            }).collect::<Vec<_>>();
        }

        sleep();
    }
}
