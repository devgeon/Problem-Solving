// BOJ-06502 / 동혁 피자
// devgeon, 2023.12.25, Java 11
// https://www.acmicpc.net/problem/6502

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int diameter = 0, width = 0, length = 0, case_num = 1;
        boolean fit = false;

        while (true) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException error) {
                System.err.println(error);
                return;
            }
            diameter = 2 * Integer.parseInt(st.nextToken());
            if (diameter == 0) {
                break;
            }
            width = Integer.parseInt(st.nextToken());
            length = Integer.parseInt(st.nextToken());

            if (width * width + length * length > diameter * diameter) {
                fit = false;
            } else {
                fit = true;
            }

            sb.append("Pizza ").append(case_num).append(fit ? " fits" : " does not fit").append(" on the table.\n");
            case_num++;
        }

        System.out.print(sb);
    }
}
