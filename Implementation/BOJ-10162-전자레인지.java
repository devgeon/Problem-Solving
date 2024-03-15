// BOJ-10162 / 전자레인지
// devgeon, 2024.03.15, Java 11
// https://www.acmicpc.net/problem/10162

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        int time = 0, count = 0;
        int[] button_times = { 5 * 60, 60, 10 };

        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        time = Integer.parseInt(br.readLine());

        for (int btn_time : button_times) {
            count = time / btn_time;
            time %= btn_time;
            sb.append(count);
            sb.append(' ');
        }

        if (time > 0) {
            bw.write(String.valueOf(-1));
        } else {
            bw.write(sb.deleteCharAt(sb.length() - 1).toString());
        }
        bw.newLine();

        bw.flush();
        br.close();
        bw.close();
    }
}
