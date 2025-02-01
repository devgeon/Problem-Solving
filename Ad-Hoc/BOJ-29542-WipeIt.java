// BOJ-29542 / Wipe it!
// devgeon, 2025.02.01, Java 11
// https://www.acmicpc.net/problem/29542

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String word = br.readLine();
        boolean[] isWritten = new boolean[26];

        for (char c : word.toCharArray()) {
            if (isWritten[c - 'a']) {
                continue;
            }
            isWritten[c - 'a'] = true;
            bw.write(c);
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
