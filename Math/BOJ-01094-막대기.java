// BOJ-01094 / 막대기
// devgeon, 2025.02.10, Java 11
// https://www.acmicpc.net/problem/1094

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int target = sc.nextInt();
        int count = 0;

        while (target > 0) {
            if ((target & 1) == 1) {
                count++;
            }
            target >>= 1;
        }
        System.out.println(count);

        sc.close();
    }
}
