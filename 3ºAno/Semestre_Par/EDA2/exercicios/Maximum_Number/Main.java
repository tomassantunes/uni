import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int children = Integer.parseInt(input.readLine());

        int max = Integer.MIN_VALUE;

        for(int i = 0; i < children; i++) {
            String[] values = input.readLine().split(" ");

            int sticks = Integer.parseInt(values[0]);

            for(int j = 1; j <= sticks; j++) {
                int n = Integer.parseInt(values[j]);
                if(n > max) max = n;
            }
        }

        System.out.println(max);
    }
}
