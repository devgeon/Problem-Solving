// BOJ-04677 / Oil Deposits
// devgeon, 2025.02.05, Java 11
// https://www.acmicpc.net/problem/4677

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;

    private static final int[] DX = { 1, 1, 0, -1, -1, -1, 0, 1 };
    private static final int[] DY = { 0, -1, -1, -1, 0, 1, 1, 1 };

    private static int solve() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());
        if (row == 0 && col == 0) {
            return -1;
        }

        boolean[][] grid = new boolean[row][col];
        for (int r = 0; r < row; r++) {
            String line = br.readLine();
            for (int c = 0; c < col; c++) {
                grid[r][c] = (line.charAt(c) == '@');
            }
        }

        int answer = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                answer += (dfs(grid, r, c) ? 1 : 0);
            }
        }
        return answer;
    }

    private static boolean dfs(final boolean[][] grid, final int row, final int col) {
        if (grid[row][col] == false) {
            return false;
        }
        grid[row][col] = false;
        for (int i = 0; i < DX.length; i++) {
            int r = row + DY[i], c = col + DX[i];
            if (0 <= r && r < grid.length && 0 <= c && c < grid[0].length && grid[r][c]) {
                dfs(grid, r, c);
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int answer = 0;
        while ((answer = solve()) >= 0) {
            bw.write(Integer.toString(answer));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
