package IntroductoryProblems.two_sets;

import java.security.spec.ECField;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;


public class Main {
    static Boolean[][] m;
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            
            boolean result = false;

            if (n*(n+1)/2 %2 != 0) {
                System.out.println("NO");
            } else {
                m = new Boolean[n+1][n*(n+1)/4 + 1];
                List<Integer>  arr= IntStream.rangeClosed(1, n).collect(ArrayList::new, List::add, List::addAll);
                result = two_sets(arr, n, n*(n+1)/4);
                System.out.println("YES");
                List<Integer> arr1 = new ArrayList<>();
                List<Integer> arr2 = new ArrayList<>();

                for (int i = 0; i<=n; i++) {
                    for (int j = 0; j<=n*(n+1)/4; j++) {
                        System.out.print(m[i][j]);
                    }
                    System.out.println();
                }

                for (int i = 1; i<=n; i++) {
                    if (m[i][n*(n+1)/4] != null && m[i][n*(n+1)/4] == true) 
                        arr1.add(arr.get(i - 1)) ;
                    else arr2.add(arr.get(i - 1));
                }

                System.out.println(arr1.size());
                arr1.forEach(e -> System.out.print(e+" "));

                System.out.println("\n"+arr2.size());
                arr2.forEach(e -> System.out.print(e+" "));
            }
            
        }
    }

    public static boolean two_sets(List<Integer> arr, int size, int sum) {

        for (int j = 0; j <= sum; j++) {
            m[0][j] = false;
        }
        for (int i = 0; i <= size; i++) {
            m[i][0] = true;
        }

        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr.get(i - 1) <= j)  {
                    m[i][j] = m[i-1][j-arr.get(i - 1)]|| 
                    m[i-1][j] ;
                }
                else {
                    m[i][j] = m[i-1][j] ;
                }
            }
        }
        return m[size][sum];
        
    }

}

