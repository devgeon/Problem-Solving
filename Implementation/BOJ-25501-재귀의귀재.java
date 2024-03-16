// BOJ-25501 / 재귀의 귀재
// devgeon, 2024.03.16, Java 11
// https://www.acmicpc.net/problem/25501

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        int num = 0, count = 0;
        String text = "";
        boolean isPalindrome = false;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        num = Integer.parseInt(br.readLine());

        for (int t = 0; t < num; t++) {
            text = br.readLine();

            isPalindrome = true;
            for (count = 1; count <= text.length() / 2; count++) {
                if (text.charAt(count - 1) != text.charAt(text.length() - count)) {
                    isPalindrome = false;
                    break;
                }
            }

            bw.write(isPalindrome ? '1' : '0');
            bw.write(' ');
            bw.write(String.valueOf(count));
            bw.newLine();
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
