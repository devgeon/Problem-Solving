// BOJ-04620 / Pascal's Travels
// devgeon, 2025.02.03, Java 11
// https://www.acmicpc.net/problem/4620

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;

    private static boolean checkPosition(int pos, int size) {
        return (0 <= pos && pos < size);
    }

    private static long solve() throws IOException {
        int size = Integer.parseInt(br.readLine());
        if (size < 0) {
            return -1;
        }

        int[][] board = new int[size][size];
        long[][] cache = new long[size][size];
        for (int row = 0; row < size; row++) {
            String line = br.readLine();
            for (int col = 0; col < size; col++) {
                board[row][col] = line.charAt(col) - '0';
            }
        }

        cache[0][0] = 1;
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                int distance = board[row][col];
                if (distance == 0) {
                    continue;
                }
                if (checkPosition(row + distance, size)) {
                    cache[row + distance][col] += cache[row][col];
                }
                if (checkPosition(col + distance, size)) {
                    cache[row][col + distance] += cache[row][col];
                }
            }
        }

        return cache[size - 1][size - 1];
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long result = 0;
        while ((result = solve()) >= 0) {
            bw.write(Long.toString(result));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
