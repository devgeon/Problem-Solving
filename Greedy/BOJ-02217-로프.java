// BOJ-02217 / 로프
// devgeon, 2025.02.27, Java 11
// https://www.acmicpc.net/problem/2217

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalRopes = Integer.parseInt(br.readLine());
        int[] ropes = new int[totalRopes];
        for (int i = 0; i < totalRopes; i++) {
            ropes[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(ropes);

        int answer = 0;
        for (int i = 0; i < totalRopes; i++) {
            answer = Math.max(answer, ropes[i] * (totalRopes - i));
        }

        bw.write(Integer.toString(answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
