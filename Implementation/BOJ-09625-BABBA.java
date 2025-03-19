// BOJ-09625 / BABBA
// devgeon, 2025.03.18, Java 11
// https://www.acmicpc.net/problem/9625

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        int countA = 1, countB = 0;
        for (int i = 0; i < num; i++) {
            int temp = countB;
            countB += countA;
            countA = temp;
        }

        System.out.println(String.format("%d %d", countA, countB));

        sc.close();
    }
}
