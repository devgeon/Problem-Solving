// BOJ-18382 / 2048
// devgeon, 2025.02.09, Java 11
// https://www.acmicpc.net/problem/18382

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final int SIZE = 4;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int initScore = Integer.parseInt(br.readLine());
        String moves = br.readLine();

        int[][] board = new int[SIZE][SIZE];
        st = new StringTokenizer(br.readLine());
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                board[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        int score = solve(board, moves);
        System.out.println(initScore + score);

        br.close();
    }

    private static int solve(int[][] board, String moves) {
        int score = 0;
        for (int i = 0; i < moves.length(); i += 4) {
            char direction = moves.charAt(i);
            score += slideBoard(board, direction);

            int num = moves.charAt(i + 1) - '0';
            int row = moves.charAt(i + 2) - '0';
            int col = moves.charAt(i + 3) - '0';
            board[row][col] = num;
        }
        return score;
    }

    private static int slideBoard(int[][] board, char direction) {
        int score = 0;
        if (direction == 'L') {
            for (int c = 0; c < SIZE; c++) {
                for (int r = 0; r < SIZE; r++) {
                    score += slideTile(board, direction, r, c);
                }
            }
        } else if (direction == 'R') {
            for (int c = SIZE - 1; c >= 0; c--) {
                for (int r = 0; r < SIZE; r++) {
                    score += slideTile(board, direction, r, c);
                }
            }
        } else if (direction == 'U') {
            for (int r = 0; r < SIZE; r++) {
                for (int c = 0; c < SIZE; c++) {
                    score += slideTile(board, direction, r, c);
                }
            }
        } else if (direction == 'D') {
            for (int r = SIZE - 1; r >= 0; r--) {
                for (int c = 0; c < SIZE; c++) {
                    score += slideTile(board, direction, r, c);
                }
            }
        }
        return score;
    }

    private static int slideTile(int[][] board, char direction, int row, int col) {
        int curr = board[row][col];
        board[row][col] = 0;

        if (direction == 'L') {
            while (col >= 0 && board[row][col] == 0) {
                col--;
            }
            if (col >= 0 && board[row][col] == curr) {
                board[row][col] += curr;
                return board[row][col];
            }
            board[row][col + 1] = curr;
        } else if (direction == 'R') {
            while (col < SIZE && board[row][col] == 0) {
                col++;
            }
            if (col < SIZE && board[row][col] == curr) {
                board[row][col] += curr;
                return board[row][col];
            }
            board[row][col - 1] = curr;
        } else if (direction == 'U') {
            while (row >= 0 && board[row][col] == 0) {
                row--;
            }
            if (row >= 0 && board[row][col] == curr) {
                board[row][col] += curr;
                return board[row][col];
            }
            board[row + 1][col] = curr;
        } else if (direction == 'D') {
            while (row < SIZE && board[row][col] == 0) {
                row++;
            }
            if (row < SIZE && board[row][col] == curr) {
                board[row][col] += curr;
                return board[row][col];
            }
            board[row - 1][col] = curr;
        }
        return 0;
    }
}
