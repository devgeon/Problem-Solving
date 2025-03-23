// BOJ-18428 / 감시 피하기
// devgeon, 2025.03.22, Java 11
// https://www.acmicpc.net/problem/18428

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static boolean solve(char[][] hall) {
        return _solve(hall, 3);
    }

    private static boolean _solve(char[][] hall, int wallLeft) {
        if (wallLeft == 0) {
            return checkVisible(hall);
        }

        int size = hall.length;
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                if (hall[r][c] != 'X') {
                    continue;
                }
                hall[r][c] = 'W';
                if (_solve(hall, wallLeft - 1)) {
                    return true;
                }
                hall[r][c] = 'X';
            }
        }
        return false;
    }

    private static boolean checkVisible(char[][] hall) {
        for (int r = 0; r < hall.length; r++) {
            for (int c = 0; c < hall[0].length; c++) {
                if (hall[r][c] != 'T') {
                    continue;
                }
                if (!checkSight(hall, r, c)) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean checkSight(char[][] hall, int row, int col) {
        int size = hall.length;
        int[] rowDiff = { 0, -1, 0, 1 };
        int[] colDiff = { 1, 0, -1, 0 };
        for (int i = 0; i < rowDiff.length; i++) {
            for (int r = row, c = col; 0 <= r && r < size && 0 <= c && c < size; r += rowDiff[i], c += colDiff[i]) {
                if (hall[r][c] == 'S')
                    return false;
                if (hall[r][c] == 'W')
                    break;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = Integer.parseInt(br.readLine());
        char[][] hall = new char[size][size];
        for (int r = 0; r < size; r++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int c = 0; c < size; c++) {
                hall[r][c] = st.nextToken().charAt(0);
            }
        }

        bw.write(solve(hall) ? "YES" : "NO");
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
