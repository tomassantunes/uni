import java.util.List;
import java.util.stream.Collectors

public class QSort {
   public static List<Integer> quickSort(List<Integer> xs) {
      if(xs.size() <= 1) return xs;

      var x0 = xs.get(0);
      List<Integer> menores = xs.stream().filter(xi -> xi < x0).collect(Collectors.toList());
      List<Integer> iguais = xs.stream().filter(xi -> xi == x0).collect(Collectors.toList());
      List<Integer> maiores = xs.stream().filter(xi -> xi > x0).collect(Collectors.toList());

      var a = quickSort(menores);
      var b = quickSort(maiores);

      a.add(x0);
      a.addAll(b);
      return a;
   }

   public static void main(String[] args) {
      
   }
}
