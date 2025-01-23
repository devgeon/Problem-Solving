// BOJ-17828 / 문자열 화폐
// devgeon, 2025.01.23, Java 11
// https://www.acmicpc.net/problem/17828

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static String solve(int length, int target) {
        int value = length, countA = length, countZ = 0;
        char middleNumber = 0;

        StringBuffer result = new StringBuffer(length);

        if (target < length || target > length * 26) {
            return "!";
        }

        while (value + 25 <= target) {
            countA--;
            countZ++;
            value += 25;
        }
        if (value < target) {
            countA--;
            middleNumber = (char) (target - value + (int) 'A');
        }

        for (int i = 0; i < countA; i++) {
            result.append('A');
        }
        if (middleNumber > 0) {
            result.append(middleNumber);
        }
        for (int i = 0; i < countZ; i++) {
            result.append('Z');
        }
        return result.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int length = 0, target = 0;

        length = Integer.parseInt(st.nextToken());
        target = Integer.parseInt(st.nextToken());

        bw.write(solve(length, target));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
