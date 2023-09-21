package sd;

import java.net.Socket;
import java.net.ServerSocket;
import java.io.InputStream;
import java.io.OutputStream;

public class EchoServer {

    private int serverPort;	
    
    public EchoServer(int p) {
	serverPort= p;		
    }
    
    
    public static void main(String[] args){
	System.err.println("SERVER...");
	if (args.length<1) {
	    System.err.println("Missing parameter: port number");	
	    System.exit(1);
	}
	int p=0;
	try {
	    p= Integer.parseInt( args[0] );
	}
	catch (Exception e) {
	    e.printStackTrace();
	    System.exit(2);
	}
	
	
	EchoServer serv= new EchoServer(p);
	serv.servico();   // activa o servico
    }

    
    // activa o servidor no porto indicado em "serverPort"
    public void servico() {
        ServerSocket ss = null;
        
	try {
            ss = new ServerSocket(serverPort);
            
            byte b[] = new byte[256];
            
            while(true) {
                Socket s = ss.accept();
                
                InputStream socIn = s.getInputStream();
                int lidos = socIn.read(b);
                String req = new String(b, 0, lidos);
                System.out.println("CLIENTE: " + req);
                
                OutputStream socOut = s.getOutputStream();
                socOut.write(req.getBytes());
                s.close();
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(ss != null) {
                try {
                    ss.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
