// BOJ-02675 / 문자열 반복
// devgeon, 2025.04.11, Java 11
// https://www.acmicpc.net/problem/2675

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

        for (int i = 0; i < num; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            String string = st.nextToken();

            for (char ch : string.toCharArray()) {
                for (int j = 0; j < count; j++) {
                    bw.write(ch);
                }
            }
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
