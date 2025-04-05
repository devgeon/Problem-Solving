// BOJ-32281 / 유리구슬 (Glass Bead)
// devgeon, 2025.04.05, Java 11
// https://www.acmicpc.net/problem/32281

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = Integer.parseInt(br.readLine());
        String beads = br.readLine();

        long len = 0, count = 0;
        for (int i = 0; i < size; i++) {
            if (beads.charAt(i) == '1') {
                len++;
            } else {
                count += len * (len + 1) / 2;
                len = 0;
            }
        }
        count += len * (len + 1) / 2;
        len = 0;

        bw.write(Long.toString(count));
        bw.flush();

        br.close();
        bw.close();
    }
}
