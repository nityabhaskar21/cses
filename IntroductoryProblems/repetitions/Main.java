package IntroductoryProblems.repetitions;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            String in = sc.nextLine();

            int maxRepetitions = 0;
            int currentRepetitions = 0;
            char prevChar = ' ';

            for (char ch: in.toCharArray()) {
                if (prevChar == ch) {
                    currentRepetitions++;
                } else {
                    currentRepetitions = 1;
                    prevChar = ch;
                }
                maxRepetitions = Integer.max(currentRepetitions, maxRepetitions);
            }
            System.out.println(maxRepetitions);
        }
    }
}
