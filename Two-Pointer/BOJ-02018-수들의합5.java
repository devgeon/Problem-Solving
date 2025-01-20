// BOJ-02018 / 수들의 합 5
// devgeon, 2025.01.20, Java 11
// https://www.acmicpc.net/problem/2018

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = 0, low = 0, high = 1, sum = 1, count = 0;
        num = Integer.parseInt(br.readLine());

        while (low <= high) {
            if (sum < num) {
                high++;
                sum += high;
            } else {
                sum -= low;
                low++;
                if (sum == num) {
                    count++;
                }
            }
        }

        bw.write(Integer.toString(count));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
