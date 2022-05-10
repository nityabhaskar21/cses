package SortingandSearching.maximum_subarray_sum;
// ACCEPTED

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static long maxSum = Long.MIN_VALUE;
    static long sum = 0;
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            sc.nextLine();
            List<Long> l = new ArrayList<Long>();

            IntStream.rangeClosed(0, n-1).forEach(i-> {
                l.add(sc.nextLong());
                sum = Long.max(sum+l.get(i), l.get(i));
                maxSum = Long.max(maxSum, sum);
            });

            System.out.println(maxSum);

        }

    }

}
