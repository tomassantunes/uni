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

        System.out.println(sn.maximumBackboneWeight());
    }
}

class SocialNetwork {
    
    int p;
    List<Edge>[] adj;

    public static final int INFINITY = Integer.MIN_VALUE;
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
        adj[person1-1].add(new Edge(person1 - 1, person2 - 1, days));
        adj[person2-1].add(new Edge(person2 - 1, person1 - 1, days));
    }

    public void union(Subset[] subsets, int x, int y) {
        int rootX = findRoot(subsets, x);
        int rootY = findRoot(subsets, y);

        if(subsets[rootY].rank < subsets[rootX].rank) {
            subsets[rootY].parent = rootX;
        } else if(subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }

    public int findRoot(Subset[] subsets, int i) {
        if(subsets[i].parent == i) {
            return subsets[i].parent;
        }

        subsets[i].parent = findRoot(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    public int maximumBackboneWeight() {
        int index = 0;
        int sum = 0;
        Edge result[] = new Edge[p];
        Subset subsets[] = new Subset[p];

        for(int i = 0; i < p; i++) {
            subsets[i] = new Subset(i, 0);
        }

        Queue<Edge> Q = new PriorityQueue<>((a,b) -> a.compareTo(b));
        for(var x : adj) {
            for(var y : x) {
                Q.add(y);
            }
        }

        int e = 0;
        while(e < p - 1) {
            Edge u = Q.remove();
            if(findRoot(subsets, u.source) != findRoot(subsets, u.destination)) {
                result[e] = u;
                union(subsets, u.source, u.destination);
                sum += u.weight;
                e++;
            }
        }

        return sum;
    }
}

class Subset {
    int parent, rank;
 
    public Subset(int parent, int rank) {
        this.parent = parent;
        this.rank = rank;
    }
}

class Edge implements Comparable<Edge> {
    public int source;
    public int destination;
    public int weight;

    public Edge(int source, int destination, int weight) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }

    public int compareTo(Edge other) {
        return other.weight - weight;
    }
}
