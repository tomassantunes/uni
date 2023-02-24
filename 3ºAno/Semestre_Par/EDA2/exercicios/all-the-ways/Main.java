import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int tests = Integer.parseInt(input.readLine());

        for(int i = 0; i < tests; i++) {
            City city = new City(Integer.parseInt(input.readLine()));

            String[] start = input.readLine().split(" ");
            String[] end = input.readLine().split(" ");

            int blocks = Integer.parseInt(input.readLine());

            for(int j = 0; j < blocks; j++) {
                String[] tmp = input.readLine().split(" ");
                city.addBlockage(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), tmp[2]);
            }

            System.out.println(city.numberOfWays(Integer.parseInt(start[0]), Integer.parseInt(start[1]), Integer.parseInt(end[0]), Integer.parseInt(end[1])));
        }    
    } 
}

class City {
    private int size;
    private int[][] city;

    public City(int size) {
        this.size = size;

        city = new int[size][size];
    }

    public void addBlockage(int x, int y, String Direction) {

    }

    public int numberOfWays(int sx, int sy, int ex, int ey) {
        return 0;
    }
}