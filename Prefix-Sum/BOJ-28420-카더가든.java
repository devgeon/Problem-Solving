// BOJ-28420 / 카더가든
// devgeon, 2025.02.14, Java 11
// https://www.acmicpc.net/problem/28420

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int caclSum(final int[][] prefixSum, final int top, final int left, final int bottom,
            final int right) {
        int result = prefixSum[bottom][right];
        result -= prefixSum[bottom][left];
        result -= prefixSum[top][right];
        result += prefixSum[top][left];
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int width = Integer.parseInt(st.nextToken());
        int carHeight = Integer.parseInt(st.nextToken());
        int caravanHeight = Integer.parseInt(st.nextToken());

        int[][] prefixSum = new int[row + 1][col + 1];
        for (int r = 1; r <= row; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= col; c++) {
                prefixSum[r][c] = Integer.parseInt(st.nextToken());
                prefixSum[r][c] += prefixSum[r - 1][c];
                prefixSum[r][c] += prefixSum[r][c - 1];
                prefixSum[r][c] -= prefixSum[r - 1][c - 1];
            }
        }

        int answer = Integer.MAX_VALUE;
        for (int r = width; r <= row; r++) {
            for (int c = carHeight + caravanHeight; c <= col; c++) {
                int fogLevel = caclSum(prefixSum, r - width, c - carHeight - caravanHeight, r, c);
                answer = Math.min(answer, fogLevel);
            }
        }
        for (int r = width + carHeight; r <= row; r++) {
            for (int c = width + caravanHeight; c <= col; c++) {
                int fogLevel = caclSum(prefixSum, r - width - carHeight, c - width - caravanHeight, r, c);
                fogLevel -= caclSum(prefixSum, r - carHeight, c - width - caravanHeight, r, c - width);
                fogLevel -= caclSum(prefixSum, r - width - carHeight, c - width, r - carHeight, c);
                answer = Math.min(answer, fogLevel);
            }
        }
        for (int r = width + caravanHeight; r <= row; r++) {
            for (int c = width + carHeight; c <= col; c++) {
                int fogLevel = caclSum(prefixSum, r - width - caravanHeight, c - width - carHeight, r, c);
                fogLevel -= caclSum(prefixSum, r - caravanHeight, c - width - carHeight, r, c - width);
                fogLevel -= caclSum(prefixSum, r - width - caravanHeight, c - width, r - caravanHeight, c);
                answer = Math.min(answer, fogLevel);
            }
        }
        System.out.println(answer);

        br.close();
    }
}
