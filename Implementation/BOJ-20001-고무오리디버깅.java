// BOJ-20001 / 고무오리 디버깅
// devgeon, 2024.04.28, Java 11
// https://www.acmicpc.net/problem/20001

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int count = 0;
        String input = br.readLine();

        while (!(input = br.readLine()).endsWith("끝")) {
            count = input.equals("문제") ? count + 1 : count == 0 ? 2 : count - 1;
        }
        bw.write(count == 0 ? "고무오리야 사랑해" : "힝구");
        bw.newLine();

        br.close();
        bw.close();
    }
}
