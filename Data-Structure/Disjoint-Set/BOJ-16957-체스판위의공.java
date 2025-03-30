// BOJ-16957 / 체스판 위의 공
// devgeon, 2025.03.27, Java 11
// https://www.acmicpc.net/problem/16957

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class DisjointSet {
    private int[] roots;

    public DisjointSet(final int size) {
        roots = new int[size + 1];
        for (int i = 1; i <= size; i++) {
            roots[i] = i;
        }
    }

    public int find(final int num) {
        if (roots[num] == num) {
            return num;
        }
        return (roots[num] = find(roots[num]));
    }

    public void union(final int a, final int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA != rootB) {
            roots[rootA] = rootB;
        }
    }

    public int[] countChilds() {
        int[] result = new int[roots.length];
        for (int num : roots) {
            result[find(num)]++;
        }
        return result;
    }
}

public class Main {
    private static final int[] DR = { 0, -1, -1, -1, 0, 1, 1, 1 };
    private static final int[] DC = { 1, 1, 0, -1, -1, -1, 0, 1 };

    private static int[][] solve(final int[][] board, final int rowSize, final int colSize) {
        DisjointSet disjointSet = new DisjointSet(rowSize * colSize);
        for (int r = 1; r <= rowSize; r++) {
            for (int c = 1; c <= colSize; c++) {
                int index = (r - 1) * colSize + c;
                int minIndex = index, minValue = board[r][c];
                for (int i = 0; i < DR.length; i++) {
                    int nr = r + DR[i], nc = c + DC[i];
                    int value = board[nr][nc];
                    if (value < minValue) {
                        minIndex = (nr - 1) * colSize + nc;
                        minValue = value;
                    }
                }
                disjointSet.union(index, minIndex);
            }
        }

        int[] result = disjointSet.countChilds();
        int[][] reshaped = new int[rowSize + 1][colSize + 1];
        for (int r = 1; r <= rowSize; r++) {
            for (int c = 1; c <= colSize; c++) {
                reshaped[r][c] = result[(r - 1) * colSize + c];
            }
        }
        return reshaped;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int rowSize = Integer.parseInt(st.nextToken());
        int colSize = Integer.parseInt(st.nextToken());

        int[][] board = new int[rowSize + 2][colSize + 2];
        for (int r = 0; r < rowSize + 2; r++) {
            board[r][0] = Integer.MAX_VALUE;
            board[r][colSize + 1] = Integer.MAX_VALUE;
        }
        for (int c = 0; c < colSize + 2; c++) {
            board[0][c] = Integer.MAX_VALUE;
            board[rowSize + 1][c] = Integer.MAX_VALUE;
        }
        for (int r = 1; r <= rowSize; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= colSize; c++) {
                board[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] result = solve(board, rowSize, colSize);
        for (int r = 1; r <= rowSize; r++) {
            for (int c = 1; c <= colSize; c++) {
                bw.write(Integer.toString(result[r][c]));
                bw.write(' ');
            }
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
