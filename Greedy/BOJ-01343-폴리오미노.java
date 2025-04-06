// BOJ-01343 / 폴리오미노
// devgeon, 2025.04.06, Java 11
// https://www.acmicpc.net/problem/1343

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static String solve(char[] board) {
        Integer count = 0;
        StringBuffer result = new StringBuffer();

        for (char c : board) {
            if (c == 'X') {
                count++;
                continue;
            }
            count = place(count, result);
            result.append('.');
            if (count != 0) {
                return "-1";
            }
        }
        count = place(count, result);
        if (count != 0) {
            return "-1";
        }

        return result.toString();
    }

    private static int place(int count, StringBuffer buffer) {
        while (count >= 4) {
            buffer.append("AAAA");
            count -= 4;
        }
        if (count == 2) {
            buffer.append("BB");
            count -= 2;
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String board = br.readLine();
        String result = solve(board.toCharArray());

        bw.write(result);
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
