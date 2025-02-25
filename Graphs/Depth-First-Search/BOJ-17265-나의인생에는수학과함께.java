// BOJ-17265 / 나의 인생에는 수학과 함께
// devgeon, 2025.02.25, Java 11
// https://www.acmicpc.net/problem/17265

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static class Result {
        private int max;
        private int min;

        public Result() {
            this.max = Integer.MIN_VALUE;
            this.min = Integer.MAX_VALUE;
        }

        public void update(int value) {
            this.max = Math.max(this.max, value);
            this.min = Math.min(this.min, value);
        }

        public void update(Result result) {
            this.max = Math.max(this.max, result.getMax());
            this.min = Math.min(this.min, result.getMin());
        }

        public int getMax() {
            return max;
        }

        public int getMin() {
            return min;
        }
    }

    private static int calculate(int a, int b, int oper) {
        switch (oper) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default:
                return a;
        }
    }

    private static Result solve(char[][] map) {
        return _solve(map, 0, 0, map[0][0] - '0', 0);
    }

    private static Result _solve(char[][] map, int row, int col, int num, int oper) {
        Result result = new Result();
        if (row >= map.length || col >= map.length) {
            return result;
        }
        if (Character.isDigit(map[row][col])) {
            num = calculate(num, map[row][col] - '0', oper);
        } else {
            oper = map[row][col];
        }
        if (row == map.length - 1 && col == map.length - 1) {
            result.update(num);
        } else {
            result.update(_solve(map, row + 1, col, num, oper));
            result.update(_solve(map, row, col + 1, num, oper));
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = Integer.parseInt(br.readLine());
        char[][] map = new char[size][size];
        for (int r = 0; r < size; r++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int c = 0; c < size; c++) {
                map[r][c] = st.nextToken().charAt(0);
            }
        }

        Result result = solve(map);
        bw.write(Integer.toString(result.getMax()));
        bw.write(' ');
        bw.write(Integer.toString(result.getMin()));
        bw.flush();

        br.close();
        bw.close();
    }
}
