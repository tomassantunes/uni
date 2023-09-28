package sd;

import java.io.*;
import java.net.*;
import java.util.List;
import java.util.LinkedList;

public class VeiculosServer {
    private int serverPort;
    private List<Registo> repositorio;
    
    public VeiculosServer(int p) {
	serverPort = p;		
	repositorio = new LinkedList<>();
    }
    
    public static void main(String[] args) {
	System.err.println("SERVER...");
	
        if (args.length<1) {
		System.err.println("Missing parameter: port number");	
		System.exit(1);
	}
        
	int p = 0;
	try {
	    p= Integer.parseInt( args[0] );
	} catch (Exception e) {
		e.printStackTrace();
		System.exit(2);
	}
	
	VeiculosServer serv= new VeiculosServer(p);
        serv.servico();
    }

    public void servico() {
        ServerSocket ss = null;
        
	try {
	    ss = new ServerSocket(serverPort);
	  
	    while (true) {
		Socket dataSocket = ss.accept();
		
		try {
                    ObjectInputStream ois = new ObjectInputStream(dataSocket.getInputStream());
                    Object objPedido = ois.readObject();
                    
                    ObjectOutputStream oos = new ObjectOutputStream(dataSocket.getOutputStream());

		    if (objPedido == null)
			System.err.println("PEDIDO NULL: esqueceu-se de alguma coisa");
		    
		    if (objPedido instanceof PedidoDeConsulta) {
			PedidoDeConsulta pc = (PedidoDeConsulta) objPedido;
                        
                        Object resposta = "DESCONHECIDO";
			
                        for(Registo r : repositorio) {
                            if(pc.getMatricula().equals(r.getMatricula())) {
                                resposta = r;
                                break;
                            }
                        }
                        
                        oos.writeObject(resposta);
                        System.out.println("O pedido de consulta foi atendido.");
		    } else if (objPedido instanceof PedidoDeRegisto) {
			PedidoDeRegisto pr = (PedidoDeRegisto) objPedido;
                        
                        int exists = 0;
                        for(Registo r : repositorio) {
                            if(r.getMatricula().equals(pr.getRegisto().getMatricula())) {
                                exists = 1;
                                break;
                            }
                        }
                        
                        String resp = null;
                        
                        if(exists == 0) {
                            repositorio.add(pr.getRegisto());
                            resp = "O registo foi adicionado com sucesso.";
                        } else {
                            resp = "O registo já existe.";
                        }
			
                        oos.writeObject(resp);
                        System.out.println("O pedido de registo foi atendido.");

		    } else
			System.out.println("PROBLEMA");
		    
                } catch (Exception exNoAtendimento) {
                    exNoAtendimento.printStackTrace();
                } finally { 
                    try {
                        dataSocket.close();
                    }
                    catch (Exception e002) {
                    }
                }
	    }
	} catch (Exception problemaBindAccept) {
	    problemaBindAccept.printStackTrace();
	}
    }
}
