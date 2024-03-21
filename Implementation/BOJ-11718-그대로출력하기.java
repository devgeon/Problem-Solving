// BOJ-11718 / 그대로 출력하기
// devgeon, 2024.03.21, Java 11
// https://www.acmicpc.net/problem/11718

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        String input = "";

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while ((input = br.readLine()) != null) {
            bw.write(input);
            bw.write('\n');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
