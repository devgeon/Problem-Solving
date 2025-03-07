// BOJ-33557 / 곱셈을 누가 이렇게 해 ㅋㅋ
// devgeon, 2025.03.06, Java 11
// https://www.acmicpc.net/problem/33557

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static boolean solve(int a, int b) {
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        String strA = Integer.toString(a);
        String strB = Integer.toString(b);

        StringBuffer result = new StringBuffer();
        int diff = strA.length() - strB.length();
        for (int i = 0; i < diff; i++) {
            result.append(strA.charAt(i));
        }
        for (int i = diff; i < strA.length(); i++) {
            result.append((strA.charAt(i) - '0') * (strB.charAt(i - diff) - '0'));
        }

        long answer = (long) a * b;
        return Long.toString(answer).equals(result.toString());

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalCases = Integer.parseInt(br.readLine());
        for (int i = 0; i < totalCases; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bw.write(solve(a, b) ? '1' : '0');
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
