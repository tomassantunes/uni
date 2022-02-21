import java.util.ArrayList;
import java.util.List;
import java.io.*;
import java.util.Collections;

public class TextFileProvider extends MemoryProvider {
   private List<String> words = new ArrayList<String>();

   public TextFileProvider(String fileName) throws IOException {
      File file = new File(fileName);

      BufferedReader reader = new BufferedReader(new FileReader(file));
   
      String text = new String();

      while((text = reader.readLine()) != null) {
         String[] line = text.split(" ");
         for(var x: line) {
            x = Cipher.normalized(x);
            if(x.length() > 0 && !words.contains(x))
               words.add(x);
         }
      } 
      reader.close();
   }
   
   public List<String> getWords() {
      Collections.sort(words);
      return words;
   }
}
