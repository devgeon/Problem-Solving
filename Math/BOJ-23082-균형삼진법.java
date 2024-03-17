// BOJ-23082 / 균형 삼진법
// devgeon, 2024.03.17, Java 11
// https://www.acmicpc.net/problem/23082

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        int num = 0;
        String result = "";
        boolean isNegative = false;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        num = Integer.parseInt(br.readLine());
        if (num < 0) {
            num *= -1;
            isNegative = true;
        }

        do {
            switch (num % 3) {
                case 0:
                    sb.append('0');
                    break;
                case 1:
                    num--;
                    sb.append(isNegative ? 'T' : '1');
                    break;
                case 2:
                    num++;
                    sb.append(isNegative ? '1' : 'T');
                    break;
            }
            num /= 3;
        } while (num > 0);

        result = sb.toString();
        for (int i = result.length() - 1; i >= 0; i--) {
            bw.write(result.charAt(i));
        }
        bw.newLine();

        bw.flush();
        br.close();
        bw.close();
    }
}
