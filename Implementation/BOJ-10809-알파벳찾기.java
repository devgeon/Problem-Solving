// BOJ-10809 / 알파벳 찾기
// devgeon, 2023.12.16, Java 11
// https://www.acmicpc.net/problem/10809

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] position = new int[26];
        Arrays.fill(position, -1);
        String word = scanner.nextLine();

        for (int i = 0; i < word.length(); i++) {
            if (position[word.charAt(i) - (int) 'a'] == -1) {
                position[word.charAt(i) - (int) 'a'] = i;
            }
        }

        for (int i = 0; i < position.length; i++) {
            System.out.print(position[i]);
            if (i == position.length - 1) {
                System.out.print("\n");
            } else {
                System.out.print(" ");
            }
        }

        scanner.close();
    }
}
