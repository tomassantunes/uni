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

        for (int i = 0; i < p; i++)
            perguntas[i] = Integer.parseInt(input.readLine());

        for (var x : perguntas) {
            Change y = coins.change(x);
            y.printOut();
        }
    }
}

// TOFIX -> Time Limit Exceeded
class Coins {
    private int nCoins;
    private int[] coins;

    public Coins(int coins) {
        this.nCoins = coins;
    }

    public void setValues(String[] values) {
        this.coins = new int[nCoins];

        for (int i = 0; i < values.length; i++)
            this.coins[i] = Integer.parseInt(values[i]);
    }

    public Change change(int amount) {
        int[] mem = new int[amount + 1];
        mem[0] = 0;

        int[] used = new int[amount + 1];
        used[0] = 0;

        for (int i = 1; i <= amount; i++) {
            mem[i] = Integer.MAX_VALUE;
            for (int j = 0; j < nCoins; j++) {
                if (i >= coins[j] && 1 + mem[i - coins[j]] < mem[i]) {
                    mem[i] = 1 + mem[i - coins[j]];
                    used[i] = coins[j];
                }
            }
        }

        return new Change(amount, mem[amount], used);
    }
}

class Change {
    private int amount;
    private int num;
    private int[] used;

    public Change(int amount, int num, int[] used) {
        this.amount = amount;
        this.num = num;
        this.used = used;
    }

    public void printOut() {
        String nums = " " + used[amount];
        int tmp = amount - used[amount];

        while (tmp > 0) {
            nums += " " + used[tmp];
            tmp -= used[tmp];
        }

        System.out.println(amount + ": [" + num + "]" + nums);
    }
}
