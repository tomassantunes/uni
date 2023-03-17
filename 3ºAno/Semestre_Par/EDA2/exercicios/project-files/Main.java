import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String[] nums = input.readLine().split(" ");
        int tasks = Integer.parseInt(nums[0]);
        int rules = Integer.parseInt(nums[1]);

        for(int i = 0; i < rules; i++) {
            String rules = input.readLine();
        }

    }
}

class Project {
    public Project(int tasks) {

    }

    public void addDependency(int task, int precedent) {

    }

    public void addDependencies(int[] rules) {

    }

    public int[] computeOrder() {
        return new int[1];
    }
}
