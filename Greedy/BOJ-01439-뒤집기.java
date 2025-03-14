// BOJ-01439 / 뒤집기
// devgeon, 2025.03.13, Java 11
// https://www.acmicpc.net/problem/1439

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String string = br.readLine();

        int answer = 0;
        if (string.charAt(0) != string.charAt(string.length() - 1)) {
            answer++;
        }
        for (int i = 1; i < string.length(); i++) {
            if (string.charAt(i - 1) != string.charAt(i)) {
                answer++;
            }
        }
        answer /= 2;

        bw.write(Integer.toString(answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
