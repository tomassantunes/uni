// NOS TESTES DO MOODLE NAO ESQUECER
// DE FAZER A CLASS PUBLICA (public class ...)

// import java.util.Scanner;
// class TransformStrings {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         String name = scanner.next();
//         String surname = scanner.next();
//         scanner.close();

//         String result = name.substring(0, 1) + " " + surname;

//         System.out.print(result);
//     }
// }

// class Calories {
//     public static void main(String[] args) {
//         Scanner s = new Scanner(System.in);
//         // INPUT (e.g. a String)
//         double weightKg = Double.parseDouble(s.nextLine());
//         s.close();
        
//         // COMPUTATION
//         double calories = 8.6182556 * weightKg;
        
//         // OUTPUT
//         System.out.println(calories);
//     }
// }

// class Determinante {
//     public static void main(String[] args) {
//         Scanner s = new Scanner(System.in);

//         double a1 = s.nextDouble();
//         double b1 = s.nextDouble();
//         double a2 = s.nextDouble();
//         double b2 = s.nextDouble();

//         s.close();

//         double result = (a1 * b2) - (b1 * a2);

//         System.out.println(result);
//     }
// }

// class PesoMercurio {
//     public static void main(String[] args) {
//         Scanner s = new Scanner(System.in);

//         double pesoTerra = s.nextDouble();

//         s.close();

//         double pesoMercurio = pesoTerra * 0.4;

//         System.out.println(pesoMercurio);
//     }
// }
// class Calc {
//     public static long calc03(int maxPower) {
//         long sum = 0;
//         for(int i = 1; i <=maxPower; i++) {
//             sum += (long)Math.pow(2, i) - 1;
//         }
        
//         return sum;
//     }
//     public static void main(String[] args) {
//         //System.out.format("%d", calc03(23)); 
        
//         int n = 1000;
//         int length = (int)(Math.log10(n)+1);
//         System.out.println(length);
//     }
// }

// import java.util.Date;

// class Primes {
    
//     private Date startTime;
    
//     public void resetTimer() {
//         startTime = new Date();
//     }
    
//     public long getElapsed() {
//         Date endTime = new Date();
        
//         long getElapsedTimeInMs = endTime.getTime() - startTime.getTime();
        
//         return getElapsedTimeInMs;
//     }
    
//     public static boolean isPrime(int n) {
//         int count = 0; 
//         for(int i = 1; i <= n; i++) {
//             if(n % i == 0) {
//                 count++;
//             }
//         }
        
//         if(count == 2) { return true; }
//         return false;
//     }
    
//     public int countPrimes(int end) {
//         int count = 0;
//         for(int i = 2; i <= end; i++) {
//             if(isPrime(i)) {
//                 count++;
//             }
//         }
        
//         return count;
//     }
    
    
// }