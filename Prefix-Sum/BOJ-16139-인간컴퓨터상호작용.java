// BOJ-16139 / 인간-컴퓨터 상호작용
// devgeon, 2025.03.04, Java 11
// https://www.acmicpc.net/problem/16139

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

        String string = br.readLine();
        int[][] prefixSum = new int[26][string.length() + 1];
        for (int i = 1; i <= string.length(); i++) {
            char c = string.charAt(i - 1);
            prefixSum[c - 'a'][i] = 1;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 2; j <= string.length(); j++) {
                prefixSum[i][j] += prefixSum[i][j - 1];
            }
        }

        int totalQueries = Integer.parseInt(br.readLine());
        for (int i = 0; i < totalQueries; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char c = st.nextToken().charAt(0);
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int answer = prefixSum[c - 'a'][end + 1] - prefixSum[c - 'a'][start];
            bw.write(Integer.toString(answer));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
