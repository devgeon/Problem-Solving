// BOJ-27941 / 하이퍼 가지 따기
// devgeon, 2023.12.24, Java 11
// https://www.acmicpc.net/problem/27941

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] big = new int[11];
        int[] small = new int[11];
        int[] big_count = new int[11];
        int[] small_count = new int[11];
        Arrays.fill(big, -1000001);
        Arrays.fill(small, 1000001);

        for (int row = 0; row < 2047; row++) {
            StringTokenizer st;
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException error) {
                System.err.println(error);
                return;
            }
            for (int idx = 0; idx < 11; idx++) {
                int x = Integer.parseInt(st.nextToken());
                if (x == big[idx]) {
                    big_count[idx]++;
                } else if (x == small[idx]) {
                    small_count[idx]++;
                } else if (small_count[idx] == 0) {
                    if (big_count[idx] == 0) {
                        big[idx] = x;
                        big_count[idx]++;
                    } else if (x < big[idx]) {
                        small[idx] = x;
                        small_count[idx]++;
                    } else {
                        small[idx] = big[idx];
                        big[idx] = x;
                        small_count[idx] = big_count[idx];
                        big_count[idx] = 1;
                    }
                }
            }
        }

        for (int idx = 0; idx < 11; idx++) {
            if (big_count[idx] - small_count[idx] < 0) {
                sb.append(big[idx]).append(" ");
            } else {
                sb.append(small[idx]).append(" ");
            }
        }
        sb.deleteCharAt(sb.length() - 1);

        System.out.println(sb);
    }
}