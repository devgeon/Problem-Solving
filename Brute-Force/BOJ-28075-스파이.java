// BOJ-28075 / 스파이
// devgeon, 2025.02.04, Java 11
// https://www.acmicpc.net/problem/28075

import java.util.Scanner;

public class Main {
    private static final int TOTAL_PLACES = 3;
    private static final int TOTAL_TASKS = 2;

    private static int[] scores = new int[TOTAL_PLACES * TOTAL_TASKS];;
    private static int target_score = 0;

    private static int solve(int total_days) {
        return _solve(total_days, 0, -1);
    }

    private static int _solve(int total_days, int score, int prevPlace) {
        if (total_days == 0) {
            return (score < target_score ? 0 : 1);
        }

        int count = 0;
        for (int i = 0; i < scores.length; i++) {
            int delta = ((i % TOTAL_PLACES) != prevPlace ? scores[i] : scores[i] / 2);
            count += _solve(total_days - 1, score + delta, i % TOTAL_PLACES);
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int total_days = sc.nextInt();
        target_score = sc.nextInt();
        for (int i = 0; i < scores.length; i++) {
            scores[i] = sc.nextInt();
        }

        int answer = solve(total_days);
        System.out.println(answer);

        sc.close();
    }
}
