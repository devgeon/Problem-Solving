// BOJ-01769 / 3의 배수
// devgeon, 2025.03.31, Java 11
// https://www.acmicpc.net/problem/1769

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String num = br.readLine();

        int count = 0;
        while (num.length() > 1) {
            int sum = 0;
            for (char ch : num.toCharArray()) {
                sum += ch - '0';
            }
            num = Integer.toString(sum);
            count++;
        }

        boolean mulOfThree = num.equals("3") || num.equals("6") || num.equals("9");
        bw.write(Integer.toString(count));
        bw.newLine();
        bw.write((mulOfThree ? "YES" : "NO"));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
