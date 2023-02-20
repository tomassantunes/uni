import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        int nTipos = Integer.parseInt(input.readLine());

        Coins coins = new Coins(nTipos);
        coins.setValues(input.readLine().split(" "));

        int p = Integer.parseInt(input.readLine());
        int[] perguntas = new int[p];

        for(int i = 0; i < p; i++) perguntas[i] = Integer.parseInt(input.readLine());

        for(var x: perguntas) {
            System.out.println(x + ": [" + coins.change(x) + "]");
        }
    }
}

class Coins {
    private int nCoins;
    private int[] coins;

      /* Cria um sistema monetário com COINS moedas diferentes. */
    public Coins(int coins) {
        this.nCoins = coins;
    }

      /* Inicializa os valores das moedas existentes. */
    public void setValues(String[] values) {
        this.coins = new int[nCoins];

        for(int i = 0; i < values.length; i++) 
            this.coins[i] = Integer.parseInt(values[i]);
    }

    /*
        Calcula e devolve o número mínimo de moedas necessário para
        obter a quantia AMOUNT.
    */
    public int change(int amount) {
        int[] mem = new int[amount + 1];
        mem[0] = 0;

        for(int i = 1; i <= amount; i++) {
            mem[i] = Integer.MAX_VALUE;

            for(int j = 0; j < nCoins; j++) {
                if(i >= this.coins[j]) {
                    int min = 1 + mem[i - this.coins[j]];
                    mem[i] = Math.min(mem[i], min);
                }
            }
        }

        return mem[amount];
    }

    // public int changeRec(int amount) {
    //     if(amount == 0) {
    //         return 0;
    //     } else {
    //         for(int q = 1; q <= amount; q++) {
    //             int min = Integer.MAX_VALUE;
    //             for(int i = 0; i < nCoins; i++) {
    //                 min = Math.min(q, coins[i] + changeRec(amount - i));
    //             }
    //         }
    //     }
    //     return min;
    // }
}