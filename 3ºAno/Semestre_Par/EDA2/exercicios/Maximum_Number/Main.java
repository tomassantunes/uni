import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static int getMax(List<Integer> arr) {
        int max = arr.get(0);

        for(var x: arr) if(x > max)  max = x;

        return max;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int children = Integer.parseInt(input.readLine());

        List<Integer> nums = new ArrayList<>();

        for(int i = 0; i < children; i++) {
            String[] values = input.readLine().split(" ");

            for(int j = 1; j < Integer.parseInt(values[0]); j++) nums.add(Integer.parseInt(values[j]));
        }

        System.out.println(getMax(nums));
    }
}
