// BOJ-32871 / 돌 게임 nm
// devgeon, 2025.01.17, Java 11
// https://www.acmicpc.net/problem/32871

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int totalCases = 0;
        long n = 0, m = 0;
        boolean answer = false;

        totalCases = Integer.parseInt(br.readLine());

        while (totalCases-- > 0) {
            st = new StringTokenizer(br.readLine());
            n = Long.parseLong(st.nextToken());
            m = Long.parseLong(st.nextToken());

            answer = (n == 1 || m == 1);
            answer |= (((n + m) & 1) == 1);
            bw.write(answer ? "YES" : "NO");
            bw.newLine();
        }

        br.close();
        bw.close();
    }
}
