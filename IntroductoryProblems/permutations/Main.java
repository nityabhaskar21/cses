package IntroductoryProblems.permutations;

//TLE

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.LongStream;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            long n = sc.nextLong();

            List<Long> perm = new ArrayList<Long>();
            if (n==1) System.out.println(1);
            else if (n > 1 && n < 4) {
                System.out.println("NO SOLUTION");
            }
            else {
                LongStream.rangeClosed(1, n).forEach(i -> {
                    if (i%2 == 0) perm.add(i);
                });
    
                LongStream.rangeClosed(1, n).forEach(i -> {
                    if (i%2 != 0) perm.add(i);
                });
                perm.forEach(i -> System.out.print(i+" "));
            }
        }
    }
}
