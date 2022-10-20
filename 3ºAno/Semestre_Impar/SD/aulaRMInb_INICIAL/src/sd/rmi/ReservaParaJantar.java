package sd.rmi;

import java.util.List;

public interface ReservaParaJantar extends java.rmi.Remote {
    
    public void adicionarReserva(String nome) throws java.rmi.RemoteException;
    
    public List<String> getList() throws java.rmi.RemoteException;
    
    public int countList() throws java.rmi.RemoteException;
}
