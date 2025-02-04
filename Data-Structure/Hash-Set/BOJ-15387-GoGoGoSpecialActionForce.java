// BOJ-15387 / Go Go Go Special Action Force!
// devgeon, 2025.02.04, Java 11
// https://www.acmicpc.net/problem/15387

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    private static final int SUB_BOARD_LENGTH = 3;
    private static final int BOARD_LENGTH = SUB_BOARD_LENGTH * SUB_BOARD_LENGTH;

    private static BufferedReader br;
    private static BufferedWriter bw;

    private static boolean solve() throws IOException {
        String[][] board = new String[BOARD_LENGTH][BOARD_LENGTH];
        for (int row = 0; row < BOARD_LENGTH; row++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int col = 0; col < BOARD_LENGTH; col++) {
                board[row][col] = st.nextToken();
            }
        }

        for (int row = 0; row < BOARD_LENGTH; row++) {
            if (checkRow(board, row) == false) {
                return false;
            }
        }
        for (int col = 0; col < BOARD_LENGTH; col++) {
            if (checkCol(board, col) == false) {
                return false;
            }
        }
        for (int row = 0; row < BOARD_LENGTH; row += 3) {
            for (int col = 0; col < BOARD_LENGTH; col += 3) {
                if (checkSubBoard(board, row, col) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean checkRow(final String[][] board, final int row) {
        HashSet<String> set = new HashSet<>();
        for (int col = 0; col < BOARD_LENGTH; col++) {
            if (set.add(board[row][col]) == false) {
                return false;
            }
        }
        return true;
    }

    private static boolean checkCol(final String[][] board, final int col) {
        HashSet<String> set = new HashSet<>();
        for (int row = 0; row < BOARD_LENGTH; row++) {
            if (set.add(board[row][col]) == false) {
                return false;
            }
        }
        return true;
    }

    private static boolean checkSubBoard(final String[][] board, final int row, final int col) {
        HashSet<String> set = new HashSet<>();
        for (int r = 0; r < SUB_BOARD_LENGTH; r++) {
            for (int c = 0; c < SUB_BOARD_LENGTH; c++) {
                if (set.add(board[row + r][col + c]) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalForces = Integer.parseInt(br.readLine());
        for (int i = 0; i < totalForces; i++) {
            boolean result = solve();
            bw.write(result ? "all 3" : "not");
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
