import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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

        project.printTasks();
    }
}

class Project {
    int nodes;
    int[][] tasks;

    private static enum Colour { WHITE, GREY, BLACK };

    public Project(int tasks) {
        this.nodes = tasks;
        this.tasks = new int[nodes][nodes];
    }

    public void addDependency(int task, int precedent) {
        tasks[task-1][precedent-1] = 1;
    }

    public void addDependencies(int[] rules) {
        for(int i = 2; i < 2 + rules[1]; i++) {
            addDependency(rules[0], rules[i]);
        }
    }

    public void printTasks() {
        for(var x : tasks) {
            for(var y : x) {
                System.out.print(y + " ");
            }
            System.out.println("");
        }
    }

    public int[] computeOrder() {
        
    }
}
