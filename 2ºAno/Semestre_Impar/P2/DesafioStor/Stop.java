import java.io.*;
import java.util.*;

public class Stop {
   public static void ex1206(File file) {
      Scanner s = new Scanner(System.in);

      FileWriter writer;
      try {
         
      writer = new FileWriter(file);
      
      String text = "";

      BufferedWriter buffer = new BufferedWriter(writer);
      while(!text.equals("STOP")) {
         text = s.nextLine();
         if(!text.equals("STOP"))
            buffer.write(text + "\n");
      }
      buffer.close();
      } catch (IOException except) {
         except.printStackTrace();
      }
   }

   public static void ex1207(File file) {
      List<String> stringsInFile = new ArrayList<String>();

      try {
         BufferedReader reader = new BufferedReader(new FileReader(file));
      
         String text = new String();

         while((text = reader.readLine()) != null) {
            stringsInFile.add(text);
         } 
         reader.close();

      } catch (IOException except) {
         except.printStackTrace();
      }

      String longer = new String();
      String shorter = new String();
      int sumLens = 0;

      for(String x: stringsInFile) {
         if( x.length() < shorter.length() || shorter.length() == 0) {
            shorter = x;
         }
         if(x.length() > longer.length()) {
            longer = x;
         }

         sumLens += x.length(); 
      }

      int med = sumLens / stringsInFile.size();

      System.out.println(shorter);
      System.out.println(longer);
      System.out.println(med);
   }

   public static void main(String[] args) {
      File myFile = new File("OneDrive/Documents/!!uni/2ºAno/Semestre_Impar/P2/DesafioStor/aula_pratica.txt");
      // ex1206(myFile);
      ex1207(myFile);

   }
}
