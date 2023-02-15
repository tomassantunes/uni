import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main 
{
    public static void main(String[] args) throws NumberFormatException, IOException 
    {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        int nTipos = Integer.parseInt(input.readLine());

        int[] tipos = new int[nTipos];

        String[] linhaTipos = input.readLine().split(" ");

        for(int i = 0; i < nTipos; i++) tipos[i] = Integer.parseInt(linhaTipos[i]);

        int p = Integer.parseInt(input.readLine());
        int[] perguntas = new int[p];

        for(int i = 0; i < p; i++) perguntas[i] = Integer.parseInt(input.readLine());
    }
}
