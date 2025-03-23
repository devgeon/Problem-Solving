// BOJ-09693 / 시파르
// devgeon, 2025.03.21, Java 11
// https://www.acmicpc.net/problem/9693

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 1;; i++) {
            int num = Integer.parseInt(br.readLine());
            if (num == 0) {
                break;
            }

            int answer = 0;
            for (int div = 5; div <= num; div *= 5) {
                answer += num / div;
            }
            bw.write(String.format("Case #%d: %d\n", i, answer));
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
