import java.util.Scanner;

public class Main {
    public static int knapSack_solver(int capacity, int[] weight, int[] value, int n) {
        int[][] temp = new int[n + 1][capacity + 1];

        for (int i = 0; i <= n; i++) {
            for (int current = 0; current <= capacity; current++) {
                if (i == 0 || current == 0) {
                    temp[i][current] = 0;
                } else if (weight[i - 1] <= current) {
                    temp[i][current] = Math.max(value[i - 1] + temp[i - 1][current - weight[i - 1]], temp[i - 1][current]);
                } else {
                    temp[i][current] = temp[i - 1][current];
                }
            }
        }

        int ans = temp[n][capacity];

        for (int i = 0; i < n + 1; i++) {
            temp[i] = null;
        }
        temp = null;

        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int s = scanner.nextInt(); 
        int n = scanner.nextInt();

        int[] weight = new int[n];
        int[] value = new int[n];

        for (int i = 0; i < n; i++) {
            weight[i] = scanner.nextInt();
            value[i] = weight[i];
        }

        int ans = knapSack_solver(s, weight, value, n);
        System.out.println(ans);

        weight = null;
        value = null;
        scanner.close();
    }
}
