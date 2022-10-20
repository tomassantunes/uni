package sd.rmi;

public class ReservaParaJantarClient {
    
    public static void main(String args[]) {
	String regHost = "localhost";
	String regPort = "9000";  // porto do binder
	String nome= "";

	if (args.length !=3) { // requer 3 argumentos
	    System.out.println
		("Usage: java sd.rmi.PalavrasClient registryHost registryPort frase");
	    System.exit(1);
	}
	regHost= args[0];
	regPort= args[1];
	nome = args[2];


	try {
	    // objeto que fica associado ao proxy para objeto remoto
	    ReservaParaJantar obj = (ReservaParaJantar) java.rmi.Naming.lookup("rmi://" + regHost +":"+regPort +"/palavras");
	    
            obj.adicionarReserva(nome);
            
            System.out.println("Número de reservas: " + obj.countList());
            System.out.println(obj.getList());
	} 
	catch (Exception ex) {
	    ex.printStackTrace();
	}
    }
}