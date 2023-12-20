// BOJ-10996 / 별 찍기 - 21
// devgeon, 2023.12.20, Java 11
// https://www.acmicpc.net/problem/10996

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int num = 0;
        Scanner scanner = new Scanner(System.in);
        StringBuilder result = new StringBuilder();

        num = scanner.nextInt();
        for (int row = 0; row < num * 2; row++) {
            for (int col = 0; col <= num; col++) {
                if (row % 2 + col % 2 != 1) {
                    result.append('*');
                } else if (col < num - 1) {
                    result.append(' ');
                } else {
                    result.append('\n');
                    break;
                }
            }
        }
        if (num == 1) {
            result.deleteCharAt(result.length() - 1);
        }

        System.out.print(result);
        scanner.close();
    }
}
