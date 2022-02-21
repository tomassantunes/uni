import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class MemoryProvider extends AbstractProvider {
    private List<String> words = new ArrayList<String>();

    public List<String> getWords() {
        Collections.sort(words);
        return words;
    }

    public void addWord(String word) {
        word = Cipher.normalized(word);
        if(word.length() > 0 && !words.contains(word))
            words.add(word);
    }

    public static void main(String[] args) {
        MemoryProvider memprovider = new MemoryProvider();
        memprovider.addWord("É");
        memprovider.addWord("o");
        memprovider.addWord("1º");
        memprovider.addWord("troço,");
        memprovider.addWord("João!");
        List<String> words = memprovider.getWords();
        System.out.println(words);
    }

}