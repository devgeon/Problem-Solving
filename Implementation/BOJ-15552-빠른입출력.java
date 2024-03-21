// BOJ-15552 / 빠른 A+B
// devgeon, 2024.03.21, Java 11
// https://www.acmicpc.net/problem/15552

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int num = 0, a = 0, b = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        num = Integer.parseInt(br.readLine());

        while (num-- > 0) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            bw.write(String.valueOf(a + b));
            bw.write('\n');
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
