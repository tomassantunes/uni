// cap 4 ex 2
/*import java.util.Locale;
import java.text.NumberFormat;
import java.util.Scanner;

class Temperature {
    private double celsius = 0.0;

    public void setCelsius(double celsius) {
        this.celsius = celsius;
    }

    public Temperature(double t) {
      setCelsius(t);
    }

    public double getCelsius() {
        return celsius;
    }

    public void setFahrenheit(double fahr) {
        setCelsius((fahr - 32) / 1.8);
    }
    
    public double getFahrenheit() {
        return 1.8 * celsius + 32;
    }
}

public class Convert {
  public static void main(String[] args) {
    // Input
    Scanner scanner = new Scanner(System.in);
    scanner.useLocale(Locale.US);
    double celsius_in = scanner.nextDouble();
    double fahrenheit_in = scanner.nextDouble();
    scanner.close();
    
    // Calc
    Temperature temperature = new Temperature(celsius_in);
    double fahrenheit_out = temperature.getFahrenheit();
    temperature.setFahrenheit(fahrenheit_in);
    double celsius_out = temperature.getCelsius();
    // Output
    //
    NumberFormat nf = NumberFormat.getInstance(Locale.US);
    nf.setMinimumFractionDigits(2);
    nf.setMaximumFractionDigits(2);
    System.out.println(nf.format(fahrenheit_out));
    System.out.println(nf.format(celsius_out));           
  } 
}
*/

// cap 4 ex 3 
/*
import java.util.Locale;
import java.util.Scanner;
import java.text.NumberFormat;

class Altura {
    private double altura = 0.0;

    public void setAltura(double altura) {
      this.altura = altura;
    }

    public Altura(double x) {
      setAltura(x);
    }

    public double pesoRecomendado(int idade) {
      return (altura - 100 + idade/10) * 0.90;
    }
}

public class Ex_04_12 {
    public static void main(String[] args) {
        // Input
        Scanner s = new Scanner(System.in);
        double altura = s.nextDouble();
        int idade = s.nextInt();
        s.close();
        
        // Calc
        Altura a = new Altura(altura);
        double p = a.pesoRecomendado(idade);
        // Output
        //
        NumberFormat nf = NumberFormat.getInstance(Locale.US);
        nf.setMinimumFractionDigits(2);
        nf.setMaximumFractionDigits(2);
        System.out.println(nf.format(p));
    }
}
*/

// cap 4 ex4
/*
import java.util.Locale;
import java.util.Scanner;
import java.text.NumberFormat;

class WeightConverter {
  private double gravidade = 0.0;

  public void setGravidade(double gravidade) {
    this.gravidade = gravidade;
  }

  public WeightConverter(double x) {
    setGravidade(x);
  }

  public double convert(double peso) {
    return peso * gravidade;
  }
}

public class Ex_04_14 {
    public static void main(String[] args) {
        // Input
        Scanner s = new Scanner(System.in);
        double gravity = s.nextDouble();
        double weightOnEarth = s.nextDouble();
        s.close();
        
        // Calc
        WeightConverter astro = new WeightConverter(gravity);
        double weightOnAstro = astro.convert(weightOnEarth);
        // Output
        //
        NumberFormat nf = NumberFormat.getInstance(Locale.US);
        nf.setMinimumFractionDigits(4);
        nf.setMaximumFractionDigits(4);
        System.out.println(nf.format(weightOnAstro));
    }
}
*/

// cap 6 ex 
class Ciclos {
  // 1.
  public int primeiraSoma() {
    int max = 100;
    int soma = 0;

    for(int i = 1; i <= 100; i++) {
      soma += i;
    }

    return soma;
  }
  
  // 2.
  public int segundaSoma() { 
    int max = 50;
    int soma = 0;

    do {
      soma += max;
      max--;
    } while(max != 0);

    return soma;
  }

  // 3.
  public int terceiraSoma() {
    long max = (long)Math.pow(2, 20) - 1;
    int soma = 0;
    
    for(int i = 1; i <= max; i++) {
      soma += i + 1;
    }

    return soma;
  }

  // 4.
  public double quartaSoma() {
    int max = 15;
    double soma = 0;

    for(int i = 1; i <= max; i++) {
      soma += Math.pow(i, -1);
    }

    return soma;
  }

  // 5.
  public long primeiroProduto() {
    int max = 20;
    long produto = 1;

    for(int i = 1; i <= max; i++) {
      produto *= i;
    }

    return produto;
  }

  // 6.
  public long segundoProduto(){
    long max = (long)Math.pow(2, 20);
    long produto = 1;
    
    for(long i = 1; i <= max; i+=2) {
      produto *= i;
    }

    return produto;
  }

  public static void main(String[] args) {
    Ciclos c = new Ciclos();

    System.out.println("1. " + c.primeiraSoma()); // 1.

    System.out.println("2. " + c.segundaSoma()); // 2.

    System.out.println("3. " + c.terceiraSoma()); // 3.

    System.out.println("4. " + c.quartaSoma()); // 4.
    
    System.out.println("5. " + c.primeiroProduto()); // 5.

    System.out.println("6. " + c.segundoProduto()); // 6.

    int num = 10;

    System.out.println((String)num.length());

  }
}
  
