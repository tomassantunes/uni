import java.util.ArrayList;
import java.util.List;
import java.text.Normalizer;

public class MemoryProvider extends AbstractProvider {
    private List<String> words = new ArrayList<String>();

    public static String normalized(String naturalText) {
        String normalizedText;
  
        normalizedText = Normalizer.normalize(naturalText, Normalizer.Form.NFD);
        normalizedText = normalizedText.toLowerCase();
        normalizedText = normalizedText.replaceAll("[^a-zA-Z0-9]", "");
  
        return normalizedText;
     }

    public List<String> getWords() {
        return words;
    }

    public void addWord(String word) {
        if(word.length() > 0 && !words.contains(word))
            words.add(normalized(word));
    }

}