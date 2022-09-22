package sd;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

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
	    p = Integer.parseInt( args[0] );
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
        ServerSocket ssock = null;
        byte[] b = new byte[256];
        
        try {
            ssock = new ServerSocket(serverPort);
            
            while(true) {
                Socket s = ssock.accept();
                
                InputStream socketIn= s.getInputStream();
                int lidos = socketIn.read(b);
                String req = new String(b, 0, lidos);
                System.out.println("CLIENTE: " + req);
                
                OutputStream socketOut= s.getOutputStream();
                socketOut.write(req.getBytes());
                s.close();
            }
                    
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(ssock != null)
                try {
                    ssock.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
        }
       
    }


}
