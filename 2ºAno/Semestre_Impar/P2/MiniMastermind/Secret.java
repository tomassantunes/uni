package MiniMastermind;

public class Secret {

    public Secret() {
        this(9);
    }

    public Result checkA(Guess guess) {
        int guess_a = guess.getA();
        if(guess_a == a) {
            return Result.FERMI;
        } else if(guess_a = b || guess_a = c) {
            return Result.NANO;
        } else {
            return Result.PICO;
        }
    }

    public boolean isSolution(Guess guess) {
        return guess.getA() == a && guess.getB() == b && guess.getC() == c;
    }
}
