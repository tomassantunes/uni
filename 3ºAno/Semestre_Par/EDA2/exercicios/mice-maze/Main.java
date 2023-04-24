import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(input.readLine());
        int E = Integer.parseInt(input.readLine());
        int T = Integer.parseInt(input.readLine());
        int M = Integer.parseInt(input.readLine());

        Maze maze = new Maze(N, E);

        for(; M > 0; M--) {
            String[] tmp = input.readLine().split(" ");
            maze.addPassage(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), Integer.parseInt(tmp[2]));
        }

        System.out.println(maze.escaped(T));
    }
}

class Maze {
    int N;
    int E;

    List<Passage>[] maze;

    @SuppressWarnings("unchecked")
    public Maze(int N, int E) {
        this.N = N;
        this.E = E - 1;

        maze = new List[N];
        for(int i = 0; i < N; i++) {
            maze[i] = new LinkedList<>();
        }
    }

    public void addPassage(int source, int destination, int time) {
        // grafo invertido para calcular as distâncias todas a partir da saída
        maze[destination-1].add(new Passage(destination-1, source-1, time));
    }

    private static final int INFINITY = Integer.MAX_VALUE;

    // Algoritmo de Dijkstra
    public int escaped(int T) {
        int[] t = new int[N];

        for(int i = 0; i < N; i++) {
            t[i] = INFINITY;
        }
        t[E] = 0;

        Queue<KeyValuePair<Integer, Integer>> Q = new PriorityQueue<>();
        Q.add(new KeyValuePair<>(0, E));

        while(!Q.isEmpty()) {
            KeyValuePair<Integer, Integer> u = Q.remove();
            
            for(Passage e : maze[u.value]) {
                int v = e.destination;
                if(t[u.value] + e.time < t[v]) {
                    t[v] = t[u.value] + e.time;
                    if(t[v] > T) break;

                    Q.add(new KeyValuePair<>(t[v], v));
                }

            }
        }

        int mice = 0;
        for(int m : t) {
            if(m <= T) mice++;
        }

        return mice;
    }
}

class Passage {
    int source;
    int destination;
    int time;

    public Passage(int s, int d, int t) {
        this.source = s;
        this.destination = d;
        this.time = t;
    }
}

class KeyValuePair<K extends Comparable<? super K>, V> implements Comparable<KeyValuePair<K,V>> {
    K key; // the value key
    V value; // the value

    public KeyValuePair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public int compareTo(KeyValuePair<K,V> aPair) {
        return key.compareTo(aPair.key);
    }
}