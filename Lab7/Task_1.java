import java.util.*;

public class Main {
    static int arr_size;
    static int position = 0;
    static ArrayList<Integer> ancestor_arr;

    public static int find_LIS(ArrayList<Integer> arr) {
        int[] d = new int[arr_size];

        for (int i = 0; i < arr_size; i++) {
            d[i] = 1;
            ancestor_arr.add(-1);
            for (int j = 0; j < i; j++) {
                if (arr.get(j) < arr.get(i)) {
                    if (d[j] + 1 > d[i]) {
                        d[i] = d[j] + 1;
                        ancestor_arr.set(i, j);
                    }
                }
            }
        }

        int ans = d[0];
        for (int i = 0; i < arr_size; i++) {
            if (d[i] > ans) {
                ans = d[i];
                position = i;
            }
        }

        return ans;
    }

    public static ArrayList<Integer> response_recovery() {
        ArrayList<Integer> path = new ArrayList<>();
        while (position != -1) {
            path.add(position);
            position = ancestor_arr.get(position);
        }

        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        arr_size = input.nextInt();

        ancestor_arr = new ArrayList<>(Collections.nCopies(arr_size, -1));
        ArrayList<Integer> arr = new ArrayList<>();

        for (int i = 0; i < arr_size; i++) {
            arr.add(input.nextInt());
        }

        int ans = find_LIS(arr);
        System.out.println(ans);

        ArrayList<Integer> storage_of_indexes = response_recovery();

        for (int i = 0; i < storage_of_indexes.size(); i++) {
            System.out.print(arr.get(storage_of_indexes.get(i)) + " ");
        }
    }
}
