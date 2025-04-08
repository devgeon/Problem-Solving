// BOJ-02581 / 소수
// devgeon, 2025.04.07, Java 11
// https://www.acmicpc.net/problem/2581

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int MAX = 10_000;

        int start = Integer.parseInt(br.readLine());
        int end = Integer.parseInt(br.readLine());

        boolean[] sieve = new boolean[MAX + 1];
        sieve[0] = sieve[1] = true;
        for (int i = 2; i < MAX; i++) {
            if (sieve[i]) {
                continue;
            }
            for (int j = i << 1; j <= MAX; j += i) {
                sieve[j] = true;
            }
        }

        int sum = 0, min = Integer.MAX_VALUE;
        for (int i = start; i <= end; i++) {
            if (!sieve[i]) {
                sum += i;
                min = Math.min(min, i);
            }
        }

        if (sum == 0) {
            bw.write("-1");
        } else {
            bw.write(Integer.toString(sum));
            bw.newLine();
            bw.write(Integer.toString(min));
        }
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
