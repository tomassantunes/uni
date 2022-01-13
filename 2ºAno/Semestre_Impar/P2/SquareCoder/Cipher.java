import java.beans.ExceptionListener;
// alinea 1
import java.text.Normalizer;

// alinea 2
import java.util.ArrayList;
//import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.Vector;
import java.util.stream.Stream;

// alinea 4
import java.util.Collections;

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
 
      for(int i = 0; i < cols; i++) {
         for(int j = 0; j < tabela.length; j++) {
            result += tabela[j].charAt(i);
         }
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
   public static List<String> explore(String candidate, List<String> words) {
      List<String> result = new Vector<>();

      for(var word: words) {
         if (candidate.startsWith(word)) {
            var suffix = candidate.substring(word.length());
            var children = explore(suffix, words);
            for(var child: children) {
               var solution = String.format("%s %s", word, child);
               result.add(solution);
            }
         }
      }
      
      if (result.isEmpty())
         result.add(candidate);

      return result;
   }

   public static List<String> breakCipher(String cipherText, List<String> words) {
      List<Integer> divisores = findDividers(cipherText.length());
      
      List<String> cipher = new ArrayList<String>();
      List<String> ciphers = new ArrayList<String>();

      int length = cipherText.length();

      for(var x: divisores) {
         String text = new String();

         for(int k = 0; k < length; k += x) {
            cipher.add(cipherText.substring(k, k + x));
         }

         for(int i = 0; i < x; i++) {
            for(var y: cipher) {
               text += y.substring(i, i+1);
            }
         }

         ciphers.add(text);
         cipher.clear();
      }

      List<List<String>> resultsCheck = new ArrayList<List<String>>();

      for(var candidate: ciphers) {
         resultsCheck.add(explore(candidate, words));
      }

      List<String> results = new ArrayList<String>();

      for(var x: resultsCheck) {
         if(x.size() > 0) {
            for(var y: x) {
               results.add(y);
            }
         }
      }

      return results;
   }

   
   public static void main(String[] args) {

      String testNormal = normalized("Bom dia, Alegria!");
      System.out.println(testNormal);

      String testEnc = encode(testNormal, 4);
      System.out.println(testEnc);
      
      List<Integer> testLen = findDividers(testEnc.length());
      System.out.println(testLen);

      List<String> dicionario = new ArrayList<String>();
      dicionario.add("bom");
      dicionario.add("alegria");
      dicionario.add("dia");
      List<String> brokenCipher = breakCipher(testEnc, dicionario);
      System.out.println(brokenCipher);

   }
}
