// BOJ-27725 / 지수를 더하자
// devgeon, 2025.02.19, Java 11
// https://www.acmicpc.net/problem/27725

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int len = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long end = Long.parseLong(br.readLine());

        int[] primes = new int[len];
        for (int i = 0; i < len; i++) {
            primes[i] = Integer.parseInt(st.nextToken());
        }

        long answer = 0;
        for (int p : primes) {
            long tmp = p;
            while (tmp <= end) {
                answer += end / tmp;
                tmp *= p;
            }
        }
        System.out.println(answer);

        br.close();
    }
}
