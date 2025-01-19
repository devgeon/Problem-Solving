// BOJ-25644 / 최대 상승
// devgeon, 2025.01.19, Java 11
// https://www.acmicpc.net/problem/25644

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int num = 0, price = 0;
        int max = 0, min = 1_000_000_000 + 1;
        int answer = 0;

        num = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < num; i++) {
            price = Integer.parseInt(st.nextToken());
            if (price < min) {
                min = price;
                max = min;
            } else if (price > max) {
                max = price;
                answer = Math.max(answer, max - min);
            }
        }

        bw.write(Integer.toString(answer));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
