// package IntroductoryProblems.number_spiral;

import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            IntStream.rangeClosed(1, t).forEach(i -> {

                long x = sc.nextLong();
                long y = sc.nextLong();
            
                if (x == y) {
                    System.out.println(x*x - (x-1));
                }
            
                else if (x > y ) {
                    if (x % 2 == 0) {
                        System.out.println(x*x - (x-1) + (x - y));
                    } else {
                        System.out.println(x*x - (x-1) - (x - y));
                    }
                }
            
                else {
                    if (y % 2 == 0) {
                        System.out.println(y*y - (y-1) - (y-x));
                    } else {
                        System.out.println(y*y - (y-1) + (y-x));
                    }
                }
            
            });

            
        }
    }
}



