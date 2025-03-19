// BOJ-17123 / 배열 놀이
// devgeon, 2025.03.19, Java 11
// https://www.acmicpc.net/problem/17123

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;

    private static void solve() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        int[] rowSum = new int[size];
        int[] colSum = new int[size];
        for (int r = 0; r < size; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < size; c++) {
                int num = Integer.parseInt(st.nextToken());
                rowSum[r] += num;
                colSum[c] += num;
            }
        }

        for (int i = 0; i < totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int r1 = Integer.parseInt(st.nextToken()) - 1;
            int c1 = Integer.parseInt(st.nextToken()) - 1;
            int r2 = Integer.parseInt(st.nextToken()) - 1;
            int c2 = Integer.parseInt(st.nextToken()) - 1;
            int value = Integer.parseInt(st.nextToken());
            int rowCount = r2 - r1 + 1, colCount = c2 - c1 + 1;

            for (int r = r1; r <= r2; r++) {
                rowSum[r] += value * colCount;
            }
            for (int c = c1; c <= c2; c++) {
                colSum[c] += value * rowCount;
            }
        }

        for (int sum : rowSum) {
            bw.write(Integer.toString(sum));
            bw.write(' ');
        }
        bw.newLine();
        for (int sum : colSum) {
            bw.write(Integer.toString(sum));
            bw.write(' ');
        }
        bw.newLine();
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalCases = Integer.parseInt(br.readLine());

        for (int i = 0; i < totalCases; i++) {
            solve();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
