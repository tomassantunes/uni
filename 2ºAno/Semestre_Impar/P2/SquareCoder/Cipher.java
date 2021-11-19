package SquareCoder;

// alinea 1
import java.text.Normalizer;

// alinea 2
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class Cipher {
	
   // alinea 1
   public static String normalized(String naturalText) {
      String normalizedText;

      normalizedText = Normalizer.normalize(naturalText, Normalizer.Form.NFD);
      normalizedText = normalizedText.toLowerCase();
      normalizedText = normalizedText.replaceAll("[^a-zA-Z0-9]", "");

      return normalizedText;
   }

   // alinea 2
   private static String[] splitToNChar(String text, int size) {
      List<String> parts = new ArrayList<>();
	
      int length = text.length();
	   for (int i = 0; i < length; i += size) {
         parts.add(text.substring(i, Math.min(length, i + size)));
      }
      return parts.toArray(new String[0]);
   }

   public static char selectAChar(String s){

      Random random = new Random();
      int index = random.nextInt(s.length());
      return s.charAt(index);

   } 

   public static String encode(String plainText, int cols) {
	   String[] tabela = splitToNChar(plainText, cols);
      
      for(int i = 0; i < tabela.length; i++) {
         
         if(tabela[i].length() < cols) {
            for(int k = tabela[i].length(); k < cols; k++) {
               tabela[i] += selectAChar(plainText);
            }
         }
      }

      String result = "";
 
      for(int j = 0; j < tabela.length; j++) {
         result += tabela[j];
      }

   	return result;
   }

   // alinea 3
   public static List<Integer> findDividers(int x) {
      // cipher.length = rows * cols
      
      List<Integer> result = new ArrayList<Integer>(); 

      for(int i = 1; i <= x; i++) {
         if(x % i == 0) result.add(i);
      }

      return result;
   }

   // alinea 4


   
   public static void main(String[] args) {

      String testNormal = normalized("Bom dia, Alegria!");
      System.out.println(testNormal);

      String testEnc = encode(testNormal, 4);
      System.out.println(testEnc);
      
      List<Integer> testLen = findDividers(testEnc.length());
      System.out.println(testLen);

   }
}
