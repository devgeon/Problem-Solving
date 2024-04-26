// BOJ-14652 / 나는 행복합니다~
// devgeon, 2024.04.26, Java 11
// https://www.acmicpc.net/problem/14652

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

        int col = 0, num = 0;

        st.nextToken();
        col = Integer.parseInt(st.nextToken());
        num = Integer.parseInt(st.nextToken());

        bw.write(String.valueOf(num / col));
        bw.write(' ');
        bw.write(String.valueOf(num % col));
        bw.newLine();

        br.close();
        bw.close();
    }
}
