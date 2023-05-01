import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        String[] arr = new String[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
        }

        int rows = n;
        int columns = m;

        int[][] dynamic_arr = new int[rows + 1][columns + 1];

        int x = 0;
        int y = 0;
        int max_len = 0;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = columns - 1; j >= 0; j--) {
                if (arr[i].charAt(j) == '5') {
                    dynamic_arr[i][j] = Math.min(Math.min(dynamic_arr[i + 1][j], dynamic_arr[i][j + 1]), dynamic_arr[i + 1][j + 1]) + 1;
                    if (dynamic_arr[i][j] > max_len) {
                        max_len = dynamic_arr[i][j];
                        x = i + 1;
                        y = j + 1;
                    }
                }
            }
        }


        System.out.println(max_len + " " + x + " " + y);

        sc.close();
    }
}
