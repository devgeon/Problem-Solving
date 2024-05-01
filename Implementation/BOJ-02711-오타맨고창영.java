// BOJ-02711 / 오타맨 고창영
// devgeon, 2024.05.01, Java 11
// https://www.acmicpc.net/problem/2711

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
        StringTokenizer st = null;

        int num = 0, idx = 0;
        String word = "";

        num = Integer.parseInt(br.readLine());
        while (num-- > 0) {
            st = new StringTokenizer(br.readLine());
            idx = Integer.parseInt(st.nextToken()) - 1;
            word = st.nextToken();
            bw.write(word.substring(0, idx));
            bw.write(word.substring(idx + 1, word.length()));
            bw.write('\n');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
