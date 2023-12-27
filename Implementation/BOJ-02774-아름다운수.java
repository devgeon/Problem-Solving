// BOJ-02774 / 아름다운 수
// devgeon, 2023.12.27, Java 11
// https://www.acmicpc.net/problem/2774

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int total_cases = 0, input = 0, score = 0;
        boolean[] check = new boolean[10];
        total_cases = Integer.parseInt(br.readLine());
        while (total_cases > 0) {
            input = Integer.parseInt(br.readLine());
            score = 0;
            Arrays.fill(check, false);
            while (input > 0) {
                if (!check[input % 10]) {
                    check[input % 10] = true;
                    score++;
                }
                input /= 10;
            }
            sb.append(score).append('\n');
            total_cases--;
        }

        System.out.print(sb);
    }
}
