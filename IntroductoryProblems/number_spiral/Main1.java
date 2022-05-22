package IntroductoryProblems.number_spiral;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main1 {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
                List<List<Long>> list = new ArrayList<List<Long>>() ;

            IntStream.rangeClosed(1, t).forEach(i -> {
                List<Long> l = new ArrayList<Long>();
                l.add(sc.nextLong());
                l.add(sc.nextLong());
                list.add(l);
            });

            list.forEach(l -> {
                long x = l.get(0);
                long y = l.get(1);
            
                if (x == y) {
                    System.out.println(x*x - (x-1));
                }
            
                else if (x > y && x % 2 == 0) {
                    System.out.println(x*x - (x-1) + (x - y));
                }
            
                else if (x > y && x % 2 != 0) {
                    System.out.println(x*x - (x-1) - (x - y));
                }
            
                else if (x < y && y % 2 == 0) {
                    System.out.println(y*y - (y-1) - (y-x));
                }
            
                else if (x < y && y % 2 != 0) {
                    System.out.println(y*y - (y-1) + (y-x));
                }
            });
            
        }
    }
}



