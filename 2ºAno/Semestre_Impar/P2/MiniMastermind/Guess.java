package MiniMastermind;

public class Guess {
    int a, b, c;
    
    public Guess(String abc) { // abc = 1 2 3
        String[] d = abc.split(" ");
        a = Integer.parseInt(d[0]);
        a = Integer.parseInt(d[1]);
        a = Integer.parseInt(d[2]);
    }

    public int getA() { return a; }

    public int getB() { return b; }
    
    public int getC() { return c; }
}
 