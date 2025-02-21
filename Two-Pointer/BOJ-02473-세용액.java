// BOJ-02473 / 세 용액
// devgeon, 2025.02.21, Java 11
// https://www.acmicpc.net/problem/2473

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int length = Integer.parseInt(br.readLine());

        int[] values = new int[length];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < length; i++) {
            values[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(values);

        long minSum = Long.MAX_VALUE;
        int[] minValues = new int[3];
        for (int i = 0; i < length - 2; i++) {
            int l = i + 1, r = length - 1;
            while (l < r) {
                long sum = (long) values[i] + values[l] + values[r];
                if (Math.abs(sum) < minSum) {
                    minSum = Math.abs(sum);
                    minValues[0] = values[i];
                    minValues[1] = values[l];
                    minValues[2] = values[r];
                }
                if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        for (int value : minValues) {
            bw.write(Integer.toString(value));
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
