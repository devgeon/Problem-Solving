// BOJ-11116 / 교통량
// devgeon, 2025.04.01, Java 11
// https://www.acmicpc.net/problem/11116

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

import static java.util.Arrays.binarySearch;

public class Main {
    private static int countCarsFromLeft(int[] leftbox, int[] rightbox) {
        int count = 0;
        for (int time : leftbox) {
            if (binarySearch(leftbox, time + 500) >= 0
                    && binarySearch(rightbox, time + 1000) >= 0
                    && binarySearch(rightbox, time + 1500) >= 0) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalCases = Integer.parseInt(br.readLine());

        for (int i = 0; i < totalCases; i++) {
            br.readLine();
            int[] leftbox = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int[] rightbox = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            int answer = countCarsFromLeft(leftbox, rightbox);

            bw.write(Integer.toString(answer));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
