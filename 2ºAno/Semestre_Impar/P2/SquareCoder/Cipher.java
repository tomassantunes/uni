package SquareCoder;

import java.text.Normalizer;

public class Cipher {
    
   public static String normalized(String naturalText) {
      String normalizedText;
      
      normalizedText = Normalizer.normalize(naturalText, Normalizer.Form.NFD);
      normalizedText = normalizedText.toLowerCase();
      normalizedText = normalizedText.replaceAll("[^a-zA-Z0-9]", "");

      return normalizedText;
   }
}
