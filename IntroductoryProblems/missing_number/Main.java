package IntroductoryProblems.missing_number;

//ACCEPTED
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static long sum = 0;
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            
            IntStream.rangeClosed(1, n-1).forEach(i-> {sum += sc.nextInt();});
            long missingNumber = (long)n*((long)n+1)/2 - sum;

            System.out.println(missingNumber);
        }
    }
}
