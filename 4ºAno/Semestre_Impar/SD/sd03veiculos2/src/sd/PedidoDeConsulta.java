/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sd;

/**
 *
 * @author tomas
 */
public class PedidoDeConsulta extends Pedido {
    private String matricula;
 
    public PedidoDeConsulta(String matricula) {
        this.matricula = matricula;
    }
 
    public String getMatricula() {
        return matricula;
    }
}
