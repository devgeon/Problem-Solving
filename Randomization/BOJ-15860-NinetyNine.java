// BOJ-15860 / Ninety-nine
// devgeon, 2025.01.26, Java 11
// https://www.acmicpc.net/problem/15860

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        final int TARGET = 99;
        int num = 1;

        while (num < TARGET) {
            System.out.println(num);
            num = scanner.nextInt();
            if (num % 3 == 0) {
                num += (int) (Math.random() * 2) + 1;
            } else {
                num += (num % 3 == 1 ? 2 : 1);
            }
        }
        System.out.println(num);

        scanner.close();
    }
}
