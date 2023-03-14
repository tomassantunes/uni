import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int E = Integer.parseInt(input.readLine());

        Organisation org = new Organisation(E);

        for(int i = 0; i < E; i++) {
            String[] line = input.readLine().split(" ");
            for(int j = 1; j <= Integer.parseInt(line[0]); j++) {
                org.addFriend(i, Integer.parseInt(line[j]));
            }
        }

        int T = Integer.parseInt(input.readLine());

        for(; T > 0; T--) {
            org.firstMaxBoom(Integer.parseInt(input.readLine()));
        }
    }
}

class Boom {
    public Boom(int maxBoom, int firstBoomDay) {
        if(maxBoom != 0 || firstBoomDay != 0) {
            System.out.println(maxBoom + " " + firstBoomDay);
            return;
        }
        System.out.println(0);
    }
}

class Organisation {
    int employees;
    List<Integer>[] friends;

    public static final int INFINITY = Integer.MAX_VALUE;
    public static final int NONE = -1;
    private static enum Colour { WHITE, GREY, BLACK };

    @SuppressWarnings("unchecked")
    public Organisation(int employees) {
        this.employees = employees;
        friends = new List[employees];

        for(int i = 0; i < employees; i++) {
            friends[i] = new LinkedList<>();
        }
    }

    public void addFriend(int employee, int friend) {
        friends[employee].add(friend);
    }

    public Boom firstMaxBoom(int source) {
        Colour[] colour = new Colour[employees];
        int[] d = new int[employees];
        int[] p = new int[employees];

        for(int u = 0; u < employees; u++) {
            colour[u] = Colour.WHITE;
            d[u] = INFINITY;
            p[u] = NONE;
        }

        colour[source] = Colour.GREY;
        d[source] = 0;
        
        Queue<Integer> Q = new LinkedList<>();
        Q.add(source);

        while(!Q.isEmpty()) {
            int u = Q.remove();

            for(Integer v : friends[u]) {
                if(colour[v] == Colour.WHITE) {
                    colour[v] = Colour.GREY;
                    
                    d[v] = d[u] + 1;
                    p[v] = u;

                    Q.add(v);
                }
                colour[u] = Colour.BLACK;
            }
        }

        int maxBoom = 0;
        int firstBoomDay = 0;
        int tmp = 0;

        for(int i = 1; i < employees; i++) {
            for(int x : d) {
                if(x == i) {
                    tmp++;
                }
            }
            if(tmp == 0) break;

            if(tmp > maxBoom) {
                maxBoom = tmp;
                firstBoomDay = i;
            }
            tmp = 0;
        }

        return new Boom(maxBoom, firstBoomDay);
    }
}