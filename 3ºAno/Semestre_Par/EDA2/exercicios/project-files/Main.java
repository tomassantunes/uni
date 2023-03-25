import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String[] nums = input.readLine().split(" ");
        int tasks = Integer.parseInt(nums[0]);
        int rulesNum = Integer.parseInt(nums[1]);

        Project project = new Project(tasks);
        
        for(; rulesNum > 0; rulesNum--) {
            String[] line = input.readLine().split(" ");
            int[] rules = new int[line.length];

            for(int i = 0; i < line.length; i++) {
                rules[i] = Integer.parseInt(line[i]);
            }

            project.addDependencies(rules);
        }

        int[] order = project.computeOrder();
        for(int i = 0; i < tasks - 1; i++) {
            System.out.print(order[i] + " ");
        }
        System.out.println(order[tasks - 1]);
    }
}

class Project {
    int nodes;
    List<Integer> tasks[];
    int[] indegree;

    @SuppressWarnings("unchecked")
    public Project(int tasks) {
        this.nodes = tasks;
        this.tasks = new List[nodes];
        indegree = new int[nodes];

        for(int i = 0; i < nodes; i++) {
            this.tasks[i] = new LinkedList<>();
        }
    }

    public void addDependency(int task, int precedent) {
        tasks[task-1].add(precedent-1);
        indegree[precedent-1]++;
    }

    public void addDependencies(int[] rules) {
        for(int i = 2; i < 2 + rules[1]; i++) {
            addDependency(rules[i], rules[0]);
        }
    }

    public int[] computeOrder() {
        PriorityQueue<Integer> Q = new PriorityQueue<>();

        for(int i = 0; i < nodes; i++) {
            if(indegree[i] == 0) Q.add(i);
        }

        List<Integer> order = new LinkedList<>();
        while(!Q.isEmpty()) {
            int u = Q.remove();
            order.add(u+1);
            
            for(int v : tasks[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    Q.add(v);
                }
            }
        }
        
        int[] result = new int[nodes];
        for(int i = 0; i < nodes; i++) {
            result[i] = order.get(i);
        }

        return result;
    }
}
