// BOJ-21918 / 전구
// devgeon, 2025.03.24, Java 11
// https://www.acmicpc.net/problem/21918

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalBulbs = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        BitSet blubs = new BitSet(totalBulbs + 1);
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= totalBulbs; i++) {
            if (st.nextToken().charAt(0) == '1') {
                blubs.set(i);
            }
        }

        for (int i = 1; i <= totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int num1 = Integer.parseInt(st.nextToken());
            int num2 = Integer.parseInt(st.nextToken());
            if (cmd == 1) {
                blubs.set(num1, num2 == 1);
            } else if (cmd == 2) {
                blubs.flip(num1, num2 + 1);
            } else if (cmd == 3) {
                blubs.clear(num1, num2 + 1);
            } else {
                blubs.set(num1, num2 + 1);
            }
        }

        for (int i = 1; i <= totalBulbs; i++) {
            bw.write(blubs.get(i) ? '1' : '0');
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
