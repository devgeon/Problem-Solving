// BOJ-16162 / 가희와 3단 고음
// devgeon, 2025.01.18, Java 11
// https://www.acmicpc.net/problem/16162

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
        StringTokenizer st = new StringTokenizer(br.readLine());

        int num = 0, a = 0, d = 0;
        int cur = 0, input = 0, answer = 0;

        num = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        cur = a;
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < num; i++) {
            input = Integer.parseInt(st.nextToken());
            if (cur == input) {
                answer++;
                cur += d;
            }
        }

        bw.write(Integer.toString(answer));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
