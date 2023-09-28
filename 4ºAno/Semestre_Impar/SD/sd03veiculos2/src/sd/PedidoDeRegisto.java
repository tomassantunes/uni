/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sd;

/**
 *
 * @author tomas
 */
public class PedidoDeRegisto extends Pedido {
    public Registo reg;
 
    public PedidoDeRegisto(Registo r) {
        this.reg = r;
    }
 
    public Registo getRegisto() {
        return reg;
    }
}
