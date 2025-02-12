// BOJ-06130 / Privileged Cows
// devgeon, 2025.02.11, Java 11
// https://www.acmicpc.net/problem/6130

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        final int MAX_NUM = 3;

        int answer = 0;
        int length = Integer.parseInt(br.readLine());

        int[] numbers = new int[length + 1];
        int[] numberCounts = new int[MAX_NUM + 1];
        int[][] positionCounts = new int[MAX_NUM + 1][MAX_NUM + 1];

        for (int i = 1; i <= length; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
            numberCounts[numbers[i]]++;
        }
        for (int i = 1; i <= MAX_NUM; i++) {
            numberCounts[i] += numberCounts[i - 1];
        }

        for (int i = 1; i <= length; i++) {
            int row = numbers[i], col = 0;
            for (int j = 1; j <= MAX_NUM; j++) {
                if (i - numberCounts[j] <= 0) {
                    col = j;
                    break;
                }
            }
            positionCounts[row][col]++;
        }

        for (int i = 1; i <= MAX_NUM; i++) {
            for (int j = 1; j <= MAX_NUM; j++) {
                if (i == j) {
                    positionCounts[i][j] = 0;
                    continue;
                }
                int exchanged = Math.min(positionCounts[i][j], positionCounts[j][i]);
                positionCounts[i][j] -= exchanged;
                positionCounts[j][i] -= exchanged;
                answer += exchanged;
            }
        }
        for (int i = 1; i <= MAX_NUM; i++) {
            for (int j = 1; j <= MAX_NUM; j++) {
                if (i == j) {
                    continue;
                }
                int k = 6 - i - j;
                int exchanged = Arrays.stream(
                        new int[] { positionCounts[i][j], positionCounts[j][k], positionCounts[k][i] })
                        .min().getAsInt();
                positionCounts[i][j] -= exchanged;
                positionCounts[j][k] -= exchanged;
                positionCounts[k][i] -= exchanged;
                answer += exchanged * 2;
            }
        }

        System.out.println(answer);
        br.close();
    }
}
