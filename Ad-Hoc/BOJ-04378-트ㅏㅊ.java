// BOJ-04378 / 트ㅏㅊ;
// devgeon, 2024.09.18, Java 11
// https://www.acmicpc.net/problem/4378

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final String KEYS = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
        String line = "";

        while ((line = br.readLine()) != null) {
            for (int i = 0; i < line.length(); i++) {
                if (line.charAt(i) == ' ') {
                    bw.write(' ');
                } else {
                    bw.write(KEYS.charAt(KEYS.indexOf(line.charAt(i)) - 1));
                }
            }
            bw.write('\n');
        }
        bw.flush();

        br.close();
        bw.close();
    }

}
