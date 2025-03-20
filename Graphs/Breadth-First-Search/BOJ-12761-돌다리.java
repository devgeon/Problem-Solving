// BOJ-12761 / 돌다리
// devgeon, 2025.03.20, Java 11
// https://www.acmicpc.net/problem/12761

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        final int MAX_POS = 100_000;

        int[] powers = new int[2];
        powers[0] = Integer.parseInt(st.nextToken());
        powers[1] = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());
        int target = Integer.parseInt(st.nextToken());

        int count = 0;
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[MAX_POS + 1];
        int[] nextPositions = new int[8];
        queue.add(start);
        queue.add(-1);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int curr = queue.remove();
            if (curr == target) {
                break;
            }
            if (curr < 0) {
                queue.add(-1);
                count++;
                continue;
            }

            nextPositions[0] = curr + 1;
            nextPositions[1] = curr - 1;
            nextPositions[2] = curr + powers[0];
            nextPositions[3] = curr + powers[1];
            nextPositions[4] = curr - powers[0];
            nextPositions[5] = curr - powers[1];
            nextPositions[6] = curr * powers[0];
            nextPositions[7] = curr * powers[1];

            for (int next : nextPositions) {
                if (0 <= next && next <= MAX_POS && !visited[next]) {
                    queue.add(next);
                    visited[next] = true;
                }
            }
        }

        bw.write(Integer.toString(count));
        bw.flush();

        br.close();
        bw.close();
    }
}
