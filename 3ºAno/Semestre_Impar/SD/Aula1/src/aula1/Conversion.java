package aula1;

public class Conversion {

    public static void main(String[] args) throws Exception {
        byte[] b = new byte[128];
        int lidos = System.in.read(b);
        
        String s = new String(b, 0, lidos - 1);
        
        System.out.println("lido: " + lidos);
        System.out.println("s: " + s + "\n");
        
        int valor = Integer.parseInt(s.substring(0, lidos - 1));
        
        System.out.println("valor: " + valor);
    }
}
