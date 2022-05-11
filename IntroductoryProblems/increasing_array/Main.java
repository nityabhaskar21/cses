package IntroductoryProblems.increasing_array;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static long moves = 0;
    static long prev = 0;
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            List<Long> l = new ArrayList<Long>();
            IntStream.rangeClosed(1, n).forEach(i ->  l.add(sc.nextLong()));
           
           prev = l.get(0);

            l.stream().forEach(e -> {
                if (e < prev) {
                    moves+= prev-e;
                } else {
                    prev = e;
                }
            });

            System.out.println(moves);
        }
    }
}
