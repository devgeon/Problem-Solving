// BOJ-01342 / 행운의 문자열
// devgeon, 2025.03.29, Java 11
// https://www.acmicpc.net/problem/1342

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static int solve(final String string) {
        int[] alphas = new int[26];
        for (char ch : string.toCharArray()) {
            alphas[ch - 'a']++;
        }
        return _solve(alphas, '\0', string.length());
    }

    private static int _solve(final int[] alphas, final char prvCh, final int ttl) {
        if (ttl == 0) {
            return 1;
        }

        int count = 0;
        for (int i = 0; i < alphas.length; i++) {
            char ch = (char) (i + 'a');
            if (alphas[i] == 0 || prvCh == ch) {
                continue;
            }
            alphas[i]--;
            count += _solve(alphas, ch, ttl - 1);
            alphas[i]++;
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String string = br.readLine();
        int answer = solve(string);
        bw.write(Integer.toString(answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
