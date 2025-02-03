// BOJ-24239 / Coins
// devgeon, 2025.02.03, Java 11
// https://www.acmicpc.net/problem/24239

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int coins = sc.nextInt();
        if (coins % 4 != 1) {
            while (true) {
                int number = (coins - 1) % 4;
                coins -= number;
                System.out.println(number);
                if (coins <= 1) {
                    break;
                }
                number = sc.nextInt();
                coins -= number;
            }
        }

        sc.close();
    }
}
