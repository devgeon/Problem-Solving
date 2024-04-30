// BOJ-02745 / 진법 변환
// devgeon, 2024.04.30, Java 11
// https://www.acmicpc.net/problem/2745

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

        int base = 0, answer = 0;
        String num = st.nextToken();
        base = Integer.parseInt(st.nextToken());

        for (int i = 0, b = 1; i < num.length(); i++) {
            char c = num.charAt(num.length() - i - 1);
            c -= (c <= '9' ? '0' : 'A' - 10);
            answer += b * (int) c;
            b *= base;
        }

        bw.write(String.valueOf(answer));
        bw.newLine();

        br.close();
        bw.close();
    }
}
