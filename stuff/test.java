import java.util.Scanner;

class Jogo {
    String[] array;

    public Jogo() {
        Scanner s = new Scanner(System.in);

        String x = s.nextLine();
        array = x.split(" ");

        System.out.println(x);
    }
}

class test {
    public static void main(String[] args) {
        Jogo a = new Jogo();
    }
}