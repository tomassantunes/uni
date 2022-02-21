import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Collections;

public class SimpleFileProvider extends MemoryProvider {
   private List<String> words = new ArrayList<String>();

   public SimpleFileProvider(String fileName) throws IOException {
      File file = new File(fileName);

      BufferedReader reader = new BufferedReader(new FileReader(file));
   
      String text = new String();

      while((text = reader.readLine()) != null) {
         text = Cipher.normalized(text);
         if(text.length() > 0 && !words.contains(text))
            words.add(text);
      } 
      reader.close();
   }

   public List<String> getWords()  {
      Collections.sort(words);
      return words;
   }

}