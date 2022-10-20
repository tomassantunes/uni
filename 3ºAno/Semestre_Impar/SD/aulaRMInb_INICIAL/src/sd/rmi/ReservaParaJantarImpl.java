package sd.rmi;

import java.rmi.server.UnicastRemoteObject;
import java.util.LinkedList;
import java.util.List;

public class ReservaParaJantarImpl extends UnicastRemoteObject implements ReservaParaJantar, java.io.Serializable {
    
    List<String> reservas = new LinkedList<>();
    
    public ReservaParaJantarImpl() throws java.rmi.RemoteException {
        super();
    }
    
    public void adicionarReserva(String nome) throws java.rmi.RemoteException {
        reservas.add(nome);
    }
    
    public List<String> getList() throws java.rmi.RemoteException {
        return reservas;
    }
    
    public int countList() throws java.rmi.RemoteException {
        return reservas.size();
    }
}
