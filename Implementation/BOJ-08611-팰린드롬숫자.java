// BOJ-08611 / 팰린드롬 숫자
// devgeon, 2025.03.14, Java 11
// https://www.acmicpc.net/problem/8611

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class Main {
    private static boolean isPalindrome(String str) {
        int len = str.length();
        int end = len >> 1;
        for (int i = 0; i < end; i++) {
            if (str.charAt(i) != str.charAt(len - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        BigInteger num = new BigInteger(br.readLine());

        int count = 0;
        for (int base = 2; base <= 10; base++) {
            String nAryNum = num.toString(base);
            if (isPalindrome(nAryNum)) {
                bw.write(Integer.toString(base));
                bw.write(' ');
                bw.write(nAryNum);
                bw.newLine();
                count++;
            }
        }
        if (count == 0) {
            bw.write("NIE");
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
