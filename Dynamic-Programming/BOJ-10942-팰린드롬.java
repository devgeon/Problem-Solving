// BOJ-10942 / 팰린드롬?
// devgeon, 2025.02.02, Java 11
// https://www.acmicpc.net/problem/10942

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static boolean solve(final int[] sequence, final int start, final int end, Boolean[][] cache) {
        if (end - start <= 2) {
            return (sequence[start] == sequence[end]);
        }
        if (cache[start][end] == null) {
            cache[start][end] = ((sequence[start] == sequence[end]) && solve(sequence, start + 1, end - 1, cache));
        }
        return cache[start][end];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int totalNumbers = Integer.parseInt(br.readLine());
        int[] sequence = new int[totalNumbers + 1];
        Boolean[][] cache = new Boolean[totalNumbers + 1][totalNumbers + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= totalNumbers; i++) {
            sequence[i] = Integer.parseInt(st.nextToken());
        }

        int totalQueries = Integer.parseInt(br.readLine());
        for (int i = 1; i <= totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            bw.write(solve(sequence, start, end, cache) ? '1' : '0');
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
