import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int nTipos = Integer.parseInt(input.readLine());

        Coins coins = new Coins(nTipos);
        coins.setValues(input.readLine().split(" "));

        int p = Integer.parseInt(input.readLine());

        for (int i = 0; i < p; i++) {
            coins.change(Integer.parseInt(input.readLine()));
        }
    }
}

class Coins {
    private int nCoins;
    private int[] coins;

    public Coins(int coins) {
        this.nCoins = coins;
    }

    public void setValues(String[] values) {
        this.coins = new int[nCoins];

        for (int i = 0; i < nCoins; i++)
            this.coins[i] = Integer.parseInt(values[i]);
    }

    public Change change(int amount) {
        int[] mem = new int[amount + 1];
        mem[0] = 0;

        int[] used = new int[amount + 1];
        used[0] = 0;

        for (int i = 1; i <= amount; i++) {
            mem[i] = Integer.MAX_VALUE;
            for (int j = 0; j < nCoins && coins[j] <= i; j++) {
                if (1 + mem[i - coins[j]] < mem[i]) {
                    mem[i] = 1 + mem[i - coins[j]];
                    used[i] = coins[j];
                }
            }
        }

        return new Change(amount, mem[amount], used);
    }
}

class Change {
    public Change(int amount, int num, int[] used) {
        String nums = " " + used[amount];
    
        for(int tmp = amount - used[amount]; tmp > 0; tmp -= used[tmp]) {
            nums += " " + used[tmp];
        }
    
        System.out.println(amount + ": [" + num + "]" + nums);
    }
}
