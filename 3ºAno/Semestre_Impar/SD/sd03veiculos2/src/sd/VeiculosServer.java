package sd;

import java.io.*;
import java.net.*;
import java.util.LinkedList;
import java.util.List;

public class VeiculosServer {
    private int serverPort;	
    
    private List<Registo> repositorio;
    
    public VeiculosServer(int p) {
	serverPort= p;		
	repositorio = new LinkedList<>(); // INICIALIZE com LinkedList
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
	
	
	VeiculosServer serv= new VeiculosServer(p);
        serv.servico();   // activa o servico
    }
    
    





    public void servico() {

	try {

            ServerSocket ss = new ServerSocket(serverPort);
	  
	    while (true) {
                
                Socket dataSocket = ss.accept();
                
		try {
		    Object objPedido= null;
                    
                    ObjectInputStream ois = new ObjectInputStream(dataSocket.getInputStream());
                    objPedido = ois.readObject();
                    
                    ObjectOutputStream oos = new ObjectOutputStream(dataSocket.getOutputStream());
		    
		    // apreciar o objecto com o pedido recebido:
		    if (objPedido==null)
			System.err.println("PEDIDO NULL: esqueceu-se de alguma coisa");
		    
		    if (objPedido instanceof PedidoDeConsulta) {
			PedidoDeConsulta pc = (PedidoDeConsulta) objPedido;
                        
                        Object resposta = "DESCONHECIDO";
                        
                        for(Registo r: repositorio) {
                            if(pc.getMatricula().equals(r.getMatricula())) {
                                resposta = r;
                                break;
                            }
                        }
                         
                        oos.writeObject(resposta);
                        
                        System.out.println("_ o pedido de consulta foi atendido.");			
		    }
		    else if (objPedido instanceof PedidoDeRegisto) {
			PedidoDeRegisto pr = (PedidoDeRegisto) objPedido; // ...


			// ver se ja existia registo desta matricula
                        boolean presente = false;
                        for(Registo r: repositorio)
                            if(r.getMatricula().equals(pr.getRegisto().getMatricula())) {
                                    presente = true;
                                    repositorio.remove(r);
                                    break;
                            }
                                    
                        repositorio.add(pr.getRegisto());
			
                        String resp = "ADICIONADO";
                        
                        if (presente) {
                            resp += ", JA ESTAVA NA LISTA";
                        }
                         
                        oos.writeObject(resp);
                        
                        System.out.println("_ o pedido de registo foi atendido.");
		    }
		    else
			System.out.println("PROBLEMA");
		    
                }
                catch (Exception exNoAtendimento) {
                    exNoAtendimento.printStackTrace();
                }
                finally {
                    try {
                        dataSocket.close();
                    }
                    catch (Exception e002) {
                    }
                }
                
		
	    
		
	    }  // ... ciclo de atendimento
	
	}
	catch (Exception problemaBindAccept) {
	    problemaBindAccept.printStackTrace();
	}

    }


}
