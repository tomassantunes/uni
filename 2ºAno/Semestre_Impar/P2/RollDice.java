import java.util.Random;

public class RollDice {
    public static void main(String[] args) {
        Die d = new Die();

        d.toss();
        System.out.println(d.getValue());

        d.toss();
        System.out.println(d.getValue());

        d.toss();
        System.out.println(d.getValue());

        
    }
}

class Die {
    private int value = 1;

    private Random generator = new Random();

    public void toss() {
        value = generator.nextInt(6) + 1;
    }

    public int getValue() {
        return value;
    }

    
}