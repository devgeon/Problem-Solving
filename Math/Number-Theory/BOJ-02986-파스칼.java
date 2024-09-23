// BOJ-02986 / 파스칼
// devgeon, 2024.09.23, Java 11
// https://www.acmicpc.net/problem/2986

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = 0, answer = -1;
        num = Integer.parseInt(br.readLine());

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                answer = num - num / i;
                break;
            }
        }
        if (answer < 0) {
            answer = num - 1;
        }

        bw.write(String.valueOf(answer));
        bw.newLine();

        br.close();
        bw.close();
    }

}
