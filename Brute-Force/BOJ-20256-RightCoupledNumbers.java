// BOJ-20256 / Right-Coupled Numbers
// devgeon, 2025.01.28, Java 11
// https://www.acmicpc.net/problem/20256

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static boolean checkRightCoupled(int number) {
        for (int n = 1; n * n <= number; n++) {
            if (number % n == 0 && number / n <= n * 2) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalNumbers = Integer.parseInt(br.readLine());
        for (int i = 0; i < totalNumbers; i++) {
            int number = Integer.parseInt(br.readLine());
            bw.write(checkRightCoupled(number) ? '1' : '0');
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
