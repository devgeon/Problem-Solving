// BOJ-20206 / 푸앙이가 길을 건너간 이유
// devgeon, 2024.09.14, Java 11
// https://www.acmicpc.net/problem/20206

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        long a = 0L, b = 0L, c = 0L;
        long x1 = 0L, x2 = 0L, y1 = 0L, y2 = 0L;
        long temp = 0L;
        boolean isDanger = false;

        st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        c = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        x1 = Long.parseLong(st.nextToken());
        x2 = Long.parseLong(st.nextToken());
        y1 = Long.parseLong(st.nextToken());
        y2 = Long.parseLong(st.nextToken());

        for (long x : List.of(x1, x2)) {
            temp = (a * x + c) * (b > 0 ? -1 : 1);
            if (y1 * Math.abs(b) < temp && temp < y2 * Math.abs(b)) {
                isDanger = true;
            }
        }
        for (long y : List.of(y1, y2)) {
            temp = (b * y + c) * (a > 0 ? -1 : 1);
            if (x1 * Math.abs(a) < temp && temp < x2 * Math.abs(a)) {
                isDanger = true;
            }
        }

        bw.write(isDanger ? "Poor" : "Lucky");
        bw.newLine();

        br.close();
        bw.close();
    }

}
