// BOJ-10952 / A+B - 5
// devgeon, 2024.03.21, Java 11
// https://www.acmicpc.net/problem/10952

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int a = 0, b = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if (a == 0 && b == 0) {
                break;
            }

            bw.write(String.valueOf(a + b));
            bw.write('\n');
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
