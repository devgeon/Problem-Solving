// BOJ-02444 / 별 찍기 - 7
// devgeon, 2023.12.17, Java 11
// https://www.acmicpc.net/problem/2444

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int num = 0, row = 0, col = 0, blank = 0;
        Scanner scanner = new Scanner(System.in);
        StringBuilder result = new StringBuilder();

        num = scanner.nextInt();
        for (row = 0; row < 2 * num - 1; row++) {
            blank = num - row - 1;
            if (blank < 0) {
                blank *= -1;
            }
            for (col = 0; col < blank; col++) {
                result.append(" ");
            }
            for (; col < 2 * num - blank - 1; col++) {
                result.append("*");
            }
            result.append("\n");
        }

        System.out.print(result);
    }
}
