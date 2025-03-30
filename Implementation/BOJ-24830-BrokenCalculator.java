// BOJ-24830 / Broken Calculator
// devgeon, 2025.03.30, Java 11
// https://www.acmicpc.net/problem/24830

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalRequests = Integer.parseInt(br.readLine());
        long result = 1;

        for (int i = 0; i < totalRequests; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            char oper = st.nextToken().charAt(0);
            int b = Integer.parseInt(st.nextToken());

            if (oper == '+') {
                result = a + b - result;
            } else if (oper == '-') {
                result *= a - b;
            } else if (oper == '*') {
                result = (long) a * b * a * b;
            } else if (oper == '/') {
                result = (a + 1) / 2;
            }

            bw.write(Long.toString(result));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
