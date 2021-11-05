package MiniMastermind;

import java.util.Scanner;

public class GameUI {
  Progress progress;

  static boolean continuePlaying(String response) {

    char c0 = response.charAt(0);

    return c0 == 's' || c0 == 'S';
  }

  void play() {
    System.out.println("START");
    

    do {
      progress = new Progress();
      do {
        String guessText = prompt("Palpite: ");
        Guess guess = new Guess(guessText);
      
        String result = progress.evalGuess(guess);
      
        System.out.printf("%2d %s |> %s%n", progress.getGuessCount(), guessText, result); 
      } while(progress.secretFound());
      System.out.format("Parabéns, resolveu em %2d palpites", progress.getGuessCount());

    } while (continuePlaying(prompt("Jogo novo?")));
    System.out.println("END");
  }

  static String prompt(String message) {
    System.out.print(message);

    Scanner s = new Scanner(System.in);
    String response = s.nextLine();

    s.close();

    return response;
  }    

  public static void main(String[] args) {
    GameUI game = new GameUI();
    game.play();
  }
}
