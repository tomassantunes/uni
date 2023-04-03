import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        
        int segments = Integer.parseInt(input.readLine());
        PolygonPhobia pp = new PolygonPhobia(segments);

        for(; segments > 0; segments--) {
            String[] tmp = input.readLine().split(" ");
            pp.addSegment(
                Integer.parseInt(tmp[0]), 
                Integer.parseInt(tmp[1]), 
                Integer.parseInt(tmp[2]), 
                Integer.parseInt(tmp[3]));
        }

        System.out.println(pp.drawableSegments());
    }
}

class PolygonPhobia {
    int p;
    int[][] map;
    List<Pair> segments;

    int c = 1;

    public static final int XMAX = 1000;
    public static final int YMAX = 1000;
    public static final int NONE = -1;

    public PolygonPhobia(int nSegments) {
        this.p = nSegments;
        map = new int[XMAX][YMAX];

        segments = new LinkedList<>();
    }

    public int getPoint(int x, int y) {
        if(map[x][y] == 0) {
            map[x][y] = c;
            c++;
        }

        return map[x][y];
    }

    public void addSegment(int x1, int y1, int x2, int y2) {
        int i = getPoint(x1, y1);
        int j = getPoint(x2, y2);

        segments.add(new Pair(i, j));
    }

    public int drawableSegments() {
        int lines = 0;
        Pair[] result = new Pair[c];

        Subset subset = new Subset(c);   
        Queue<Pair> Q = new LinkedList<>();

        for(var x : segments) Q.add(x);

        int e = 0;
        while(!Q.isEmpty()) {
            Pair u = Q.remove();
            if(subset.findRoot(u.i) != subset.findRoot(u.j)) {
                result[e] = u;
                subset.union(u.i, u.j);
                lines++;
                e++;
            }
        }

        return lines;
    }
}

class Pair {
    int i;
    int j;

    public Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }
}

class Subset {
    int parent[];

    public Subset(int n) {
        parent = new int[n];

        for(int i = 0; i < n; i++) {
            parent[i] = -1;
        }
    }

    public void union(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if(parent[rootY] < parent[rootX]) {
            parent[rootY] += parent[rootX];
            parent[rootX] = rootY;
        } else {
            parent[rootX] += parent[rootY];
            parent[rootY] = rootX;
        }
    }

    public int findRoot(int i) {
        while(parent[i] > 0) {
            i = parent[i];
        }

        return i;
    }
}