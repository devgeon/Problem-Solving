// BOJ-26005 / 나뭇잎 학회
// devgeon, 2025.02.18, Java 11
// https://www.acmicpc.net/problem/26005

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        int answer = (num == 1 ? 0 : (num * num - 1) / 2 + 1);
        System.out.println(answer);

        sc.close();
    }
}
