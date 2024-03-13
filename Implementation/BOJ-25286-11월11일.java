// BOJ-25286 / 11월 11일
// devgeon, 2024.03.13, Java 11
// https://www.acmicpc.net/problem/25286

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int num = 0, year = 0, month = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        num = Integer.parseInt(br.readLine());

        for (int i = 0; i < num; i++) {
            st = new StringTokenizer(br.readLine());
            year = Integer.parseInt(st.nextToken());
            month = Integer.parseInt(st.nextToken());

            bw.write(String.valueOf(month == 1 ? year - 1 : year));
            bw.write(' ');
            bw.write(String.valueOf(month == 1 ? 12 : month - 1));
            bw.write(' ');

            switch (month - 1) {
                case 4:
                case 6:
                case 9:
                case 11:
                    bw.write(String.valueOf(30));
                    break;
                case 2:
                    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                        bw.write(String.valueOf(29));
                    } else {
                        bw.write(String.valueOf(28));
                    }
                    break;
                default:
                    bw.write(String.valueOf(31));
            }
            bw.newLine();
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
