// BOJ-06996 / 애너그램
// devgeon, 2023.12.23, Java 11
// https://www.acmicpc.net/problem/6996

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static int[] count = new int[26];

    private static boolean solveAnagrams(String first, String second) {
        Arrays.fill(count, 0);

        for (int i = 0; i < first.length(); i++) {
            count[(int) first.charAt(i) - (int) 'a']++;
        }
        for (int i = 0; i < second.length(); i++) {
            count[(int) second.charAt(i) - (int) 'a']--;
        }

        for (int cnt : count) {
            if (cnt != 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder result = new StringBuilder();
        int cases = scanner.nextInt();

        while (cases > 0) {
            String first = scanner.next();
            String second = scanner.next();

            result.append(first).append(" & ").append(second).append(" are ");
            result.append(solveAnagrams(first, second) ? "anagrams." : "NOT anagrams.").append("\n");

            cases--;
        }

        System.out.println(result);
        scanner.close();
    }
}
