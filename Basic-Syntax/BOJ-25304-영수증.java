// BOJ-25304 / 영수증
// devgeon, 2023.12.13, Java 11
// https://www.acmicpc.net/problem/25304

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int total_price = 0, type_count = 0, price = 0, count = 0;

        total_price = scanner.nextInt();
        type_count = scanner.nextInt();
        for (int i = 0; i < type_count; i++) {
            price = scanner.nextInt();
            count = scanner.nextInt();
            total_price -= price * count;
        }

        if (total_price == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}
