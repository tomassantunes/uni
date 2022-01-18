import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class QSort {
   public static List<Integer> quickSort(List<Integer> xs) {
      if(xs.size() <= 1) return xs;

      var x0 = xs.get(0);
      // List<Integer> menores = xs.stream().filter(xi -> xi < x0).collect(Collectors.toList());
      // List<Integer> iguais = xs.stream().filter(xi -> xi == x0).collect(Collectors.toList());
      // List<Integer> maiores = xs.stream().filter(xi -> xi > x0).collect(Collectors.toList());

      List<Integer> less = new ArrayList<Integer>();
      List<Integer> equal = new ArrayList<Integer>();
      List<Integer> bigger = new ArrayList<Integer>();

      for(var x: xs) {
         if(x < x0)
            less.add(x);
         else if(x == x0)
            equal.add(x);
         else if(x > x0) 
            bigger.add(x);
      }

      var a = quickSort(less);
      var b = quickSort(bigger);

      a.add(x0);
      a.addAll(b);
      return a;
   }

   public static void main(String[] args) {
      var x = List.of(9, 2, 1, 3, 12, 22, 50, 69, 420);
      var y = quickSort(x);
      System.out.println(y);
   }
}
