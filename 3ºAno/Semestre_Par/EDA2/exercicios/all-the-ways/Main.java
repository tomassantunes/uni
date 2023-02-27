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
    private int[][] city;
    private String[][] blocks;

    public City(int size) {
        city = new int[size][size];
        blocks = new String[size][size];
    }
    
    public void addBlockage(int x, int y, String Direction) {
        if(Direction.equals("W")) {
            blocks[x-2][y-1] = "E";
            return;
        }

        if(Direction.equals("S")) {
            blocks[x-1][y-2] = "N";
            return;
        }

        blocks[x-1][y-1] = Direction;
    }

    public void printCity() {
        for(var x: city) {
            for(var y: x) {
                System.out.print(y + " ");
            }
            System.out.println("");
        }
    }
    
    public int numberOfWays(int sx, int sy, int ex, int ey) {
        city[ex-1][ey-1] = 1;

        for(int i = ex - 2; i >= sx-1; i--)
            if(blocks[i][ey-1] == null || !blocks[i][ey-1].equals("E"))
                city[i][ey-1] = city[i+1][ey-1];
        
        for(int i = ey - 2; i >= sy-1; i--)
            if(blocks[ex-1][i] == null || !blocks[ex-1][i].equals("N"))
                city[ex-1][i] = city[ex-1][i+1];

        for(int i = ex - 2; i >= sx-1; i--) {
            for(int j = ey - 2; j >= sy-1; j--) {
                if(blocks[i][j] == null || !blocks[i][j].equals("E"))
                    city[i][j] += city[i+1][j];

                if(blocks[i][j] == null || !blocks[i][j].equals("N"))
                    city[i][j] += city[i][j+1];
            }
        }

        return city[sx-1][sy-1];
    }
}