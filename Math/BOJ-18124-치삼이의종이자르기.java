// BOJ-18124 / 치삼이의 종이 자르기
// devgeon, 2024.09.12, Java 11
// https://www.acmicpc.net/problem/18124

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        long num = 0, answer = 0;
        num = Long.parseLong(br.readLine());

        for (long i = 1;; i *= 2) {
            if (i * 2 < num) {
                answer += i;
                continue;
            }
            answer += (num + 1) / 2;
            break;
        }

        if (num == 1) {
            answer = 0;
        }

        bw.write(String.valueOf(answer));
        bw.newLine();

        br.close();
        bw.close();
    }

}
