// BOJ-21600 / 계단
// devgeon, 2025.04.03, Java 11
// https://www.acmicpc.net/problem/21600

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

        int num = Integer.parseInt(br.readLine());
        int len = 0, maxLen = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {
            int height = Integer.parseInt(st.nextToken());
            len = Math.min(len + 1, height);
            maxLen = Math.max(len, maxLen);
        }

        bw.write(Integer.toString(maxLen));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
