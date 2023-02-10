import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException{

        long startTime = System.nanoTime();

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int children = Integer.parseInt(input.readLine());
        
        int valueMax=0;

        for(int i =0; i<children; i++){

            String[] values = input.readLine().split(" ");

            for(int j=0;j<=Integer.parseInt(values[0]);j++){

                if(valueMax<Integer.parseInt(values[j])){
                    valueMax=Integer.parseInt(values[j]);
                }
            
            }
            
        }
        
        System.out.println(valueMax);
        
        long endTime   = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println(totalTime);

    }










}
