import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class SimpleFileProvider extends MemoryProvider {
   List<String> words = new ArrayList<String>();

   public SimpleFileProvider(String fileName) {
      try {
         File file = new File(fileName);
         Scanner s = new Scanner(file);
         
         while (s.hasNextLine()) {
            String data = s.nextLine();
            if(data.length() > 0 && !words.contains(data))
               words.add(normalized(data));
         }

         s.close();
      } catch (IOException e) {
         e.printStackTrace();
      }
   }

   public List<String> getWords()  {
      return words;
   }

   public static void main(String[] args) {
      try {
         AbstractProvider p = new SimpleFileProvider("test.txt"); 
         java.util.List<String> words = p.getWords();
         if (!words.equals(java.util.List.of("a", "b"))) throw new Exception("FAIL");
         System.out.print("PASS");
      } catch (Exception e) {}
   }

}