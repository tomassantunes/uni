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
    private long[][] city;
    private int[][] blocks_horizontal;
    private int[][] blocks_vertical;

    public City(int size) {
        city = new long[size][size];
        blocks_horizontal = new int[size][size];
        blocks_vertical = new int[size][size];
    }
    
    public void addBlockage(int x, int y, String Direction) {
        if(Direction.equals("S")) {
            blocks_vertical[x-1][y-2] = 1; // N -> 1
            return;
        }

        if(Direction.equals("W")) {
            blocks_horizontal[x-2][y-1] = 1; // E -> 2
            return;
        }

        if(Direction.equals("N")) blocks_vertical[x-1][y-1] = 1;
        if(Direction.equals("E")) blocks_horizontal[x-1][y-1] = 1;
    }

    public long numberOfWays(int sx, int sy, int ex, int ey) {
        city[ex-1][ey-1] = 1;

        for(int i = ex - 2; i >= sx-1; i--)
            if(blocks_horizontal[i][ey-1] != 1)
                city[i][ey-1] = city[i+1][ey-1];
        
        for(int i = ey - 2; i >= sy-1; i--)
            if(blocks_vertical[ex-1][i] != 1)
                city[ex-1][i] = city[ex-1][i+1];

        for(int i = ex - 2; i >= sx-1; i--) {
            for(int j = ey - 2; j >= sy-1; j--) {
                if(blocks_horizontal[i][j] != 1) {
                    city[i][j] += city[i+1][j];
                }

                if(blocks_vertical[i][j] != 1) {
                    city[i][j] += city[i][j+1];
                }
            }
        }

        return city[sx-1][sy-1];
    }
}
