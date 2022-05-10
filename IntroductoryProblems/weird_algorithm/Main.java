package IntroductoryProblems.weird_algorithm;

//ACCEPTED

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            List<Long> result = new ArrayList<Long>();

            long n = sc.nextLong();
            result.add((long)n);

            while (n != 1) {
                if (n%2 == 0) {
                    n = n/2;
                    result.add(n);
                } else {
                    n = n*3+1;
                    result.add(n);
                }
            }
            result.forEach(e -> System.out.print(e+" "));
        }
    }
}
