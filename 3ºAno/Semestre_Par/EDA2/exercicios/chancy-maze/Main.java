import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

class Main {
    public static void main(String[] args) throws IOException, NumberFormatException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = input.readLine().split(" ");

        int R = Integer.parseInt(tmp[0]); // rooms
        int C = Integer.parseInt(tmp[1]); // corridors
        
        Maze maze = new Maze(R, C);

        for(; C > 0; C--) {
            tmp = input.readLine().split(" ");
            maze.addCorridor(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), tmp[2].charAt(0), Integer.parseInt(tmp[3]));
        }

        int lose = maze.contestantMayLose(0, R-1);
        if(lose == 0) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }
}

class Maze {
    int R;
    int C;
    List<Corridor>[] corridors;

    @SuppressWarnings("unchecked")
    public Maze(int R, int C) {
        this.R = R;
        this.C = C;

        corridors = new List[R];
        for(int i = 0; i < R; i++) {
            corridors[i] = new LinkedList<>();
        }
    }

    public void addCorridor(int i, int j, char type, int G) {
        if(type == 'C') {
            G *= -1;
        }

        corridors[i].add(new Corridor(i, j, G));
    }

    private static final int INFINITY = Integer.MAX_VALUE;

    public int contestantMayLose(int start, int end) {
        int[] d = new int[R];
        for(int i = 0; i < R; i++) {
            d[i] = INFINITY;
        }
        d[start] = 0;

        for(int i = 1; i < R; i++) {
            for(int j = 0; j < R; j++) {
                for(Corridor c : corridors[j]) {
                    if(d[c.source] != INFINITY && d[c.source] + c.coins < d[c.destination]) {
                        d[c.destination] = d[c.source] + c.coins;
                    }
                }
            }
        }

        if(d[end] < 0) return 0;

        for(int i = 0; i < R; i++) {
            for(Corridor c : corridors[i]) {
                if(d[c.source] != INFINITY && d[c.source] + c.coins < d[c.destination]) {
                    return 0;
                }
            }
        }

        return 1;
    }
}

class Corridor {
    public int source;
    public int destination;
    public int coins;

    public Corridor(int s, int d, int c) {
        this.source = s;
        this.destination = d;
        this.coins = c;
    }
}