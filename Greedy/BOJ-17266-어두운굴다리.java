// BOJ-17266 / 어두운 굴다리
// devgeon, 2025.03.26, Java 11
// https://www.acmicpc.net/problem/17266

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

        int totalDistance = Integer.parseInt(br.readLine());
        int totalLights = Integer.parseInt(br.readLine());

        int[] positions = new int[totalLights];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < totalLights; i++) {
            positions[i] = Integer.parseInt(st.nextToken());
        }

        int minLen = Math.max(positions[0], totalDistance - positions[totalLights - 1]);
        for (int i = 1; i < positions.length; i++) {
            int len = (positions[i] - positions[i - 1] + 1) >> 1;
            minLen = Math.max(len, minLen);
        }

        bw.write(Integer.toString(minLen));
        bw.flush();

        br.close();
        bw.close();
    }
}
