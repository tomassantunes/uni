import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Comparator;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String[] linha = input.readLine().split(" ");

        int p = Integer.parseInt(linha[0]);
        int r = Integer.parseInt(linha[1]);

        SocialNetwork sn = new SocialNetwork(p);

        for(; r > 0; r--) {
            String[] tmp = input.readLine().split(" ");
            sn.addRelation(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), Integer.parseInt(tmp[2]));
        }

        System.out.println(sn.maximumBackboneWeight() + "\n");
    }
}

class SocialNetwork {
    
    int p;
    List<Edge>[] adj;

    public static final int INFINITY = Integer.MAX_VALUE;
    public static final int NONE = -1;

    @SuppressWarnings("unchecked")
    public SocialNetwork(int nPersons) {
        this.p = nPersons;
        adj = new List[nPersons];

        for(int i = 0; i < nPersons; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    public void addRelation(int person1, int person2, int days) {
        adj[person1-1].add(new Edge(person2 - 1, days));
        adj[person2-1].add(new Edge(person1 - 1, days));
    }

    public int maximumBackboneWeight() {
        int[] key = new int[this.p];
        int[] p = new int[this.p];
        int maxWeight = 0;

        for(int i = 0; i < this.p; i++) {
            key[i] = INFINITY;
            p[i] = NONE;
        }

        key[0] = 0;
        Queue<Edge> Q = new PriorityQueue<>((a,b) -> a.compareTo(b));
        Q.add(new Edge(0, 0));

        while(!Q.isEmpty()) {
            Edge u = Q.remove();

            for(Edge v : adj[u.destination]) {
                if(Q.contains(v) && u.weight > v.weight) {
                    p[v.destination] = u.destination;
                    key[v.destination] = u.weight;

                    Q.add(new Edge(p[v.destination], key[v.destination]));
                }
            }
        }

        return key[this.p - 1];
    }
}

class Edge implements Comparable<Edge> {
    public int destination;
    public int weight;

    public Edge(int destination, int weight) {
        this.destination = destination;
        this.weight = weight;
    }

    public int compareTo(Edge other) {
        return weight - other.weight;
    }
}
