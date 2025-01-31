// BOJ-01999 / 최대최소
// devgeon, 2025.01.31, Java 11
// https://www.acmicpc.net/problem/1999

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        final int MAX = 250;
        int matrixSize = Integer.parseInt(st.nextToken());
        int submatrixSize = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        List<List<Integer>> matrix = new ArrayList<>(matrixSize);
        List<List<Integer>> cache = new ArrayList<>(matrixSize - submatrixSize + 1);
        for (int r = 0; r < matrixSize; r++) {
            matrix.add(new ArrayList<>(matrixSize));
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < matrixSize; c++) {
                matrix.get(r).add(Integer.parseInt(st.nextToken()));
            }
        }
        for (int r = 0, end = matrixSize - submatrixSize + 1; r < end; r++) {
            cache.add(new ArrayList<>(matrixSize - submatrixSize + 1));
            for (int c = 0; c < end; c++) {
                cache.get(r).add(-1);
            }
        }

        for (int i = 0; i < totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken()) - 1;
            int col = Integer.parseInt(st.nextToken()) - 1;

            if (cache.get(row).get(col) == -1) {
                int max = 0, min = MAX;
                for (int r = row, rowEnd = row + submatrixSize; r < rowEnd; r++) {
                    for (int c = col, colEnd = col + submatrixSize; c < colEnd; c++) {
                        max = Math.max(max, matrix.get(r).get(c));
                        min = Math.min(min, matrix.get(r).get(c));
                    }
                }
                cache.get(row).set(col, max - min);
            }
            bw.write(Integer.toString(cache.get(row).get(col)));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
