// BOJ-02342 / Dance Dance Revolution
// devgeon, 2025.02.13, Java 11
// https://www.acmicpc.net/problem/2342

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[][][] cache = new int[5][5][2];

        int count = 0;
        int next = Integer.parseInt(st.nextToken());
        cache[0][next][count] = 2;
        cache[next][0][count] = 2;

        while ((next = Integer.parseInt(st.nextToken())) > 0) {
            for (int left = 0; left < 5; left++) {
                for (int right = 0; right < 5; right++) {
                    if (cache[left][right][count & 1] == 0) {
                        continue;
                    }
                    if (left != next) {
                        int delta = (right == next ? 1 : (right == 0 ? 2 : (Math.abs(right - next) == 2 ? 4 : 3)));
                        int prev = cache[left][next][(count + 1) & 1];
                        int curr = cache[left][right][count & 1] + delta;
                        prev = (prev == 0 ? Integer.MAX_VALUE : prev);
                        cache[left][next][(count + 1) & 1] = Math.min(prev, curr);
                    }
                    if (right != next) {
                        int delta = (left == next ? 1 : (left == 0 ? 2 : (Math.abs(left - next) == 2 ? 4 : 3)));
                        int prev = cache[next][right][(count + 1) & 1];
                        int curr = cache[left][right][count & 1] + delta;
                        prev = (prev == 0 ? Integer.MAX_VALUE : prev);
                        cache[next][right][(count + 1) & 1] = Math.min(prev, curr);
                    }
                    cache[left][right][count & 1] = 0;
                }
            }
            count++;
        }

        int answer = Integer.MAX_VALUE;
        for (int left = 0; left < 5; left++) {
            for (int right = 0; right < 5; right++) {
                if (cache[left][right][count & 1] == 0) {
                    continue;
                }
                answer = Math.min(answer, cache[left][right][count & 1]);
            }
        }
        System.out.println(answer);

        br.close();
    }
}
