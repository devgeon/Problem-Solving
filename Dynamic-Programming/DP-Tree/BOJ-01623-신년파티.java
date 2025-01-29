// BOJ-01623 / 신년 파티
// devgeon, 2025.01.29, Java 11
// https://www.acmicpc.net/problem/1623

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static void calculateMaxScores(final List<Integer> scores, final List<List<Integer>> adjacencyList,
            final int current, List<List<Integer>> cache) {
        cache.get(1).set(current, scores.get(current));
        for (int inferior : adjacencyList.get(current)) {
            calculateMaxScores(scores, adjacencyList, inferior, cache);
            int maxInferiorScore = Math.max(cache.get(0).get(inferior), cache.get(1).get(inferior));
            cache.get(0).set(current, cache.get(0).get(current) + maxInferiorScore);
            cache.get(1).set(current, cache.get(1).get(current) + cache.get(0).get(inferior));
        }
    }

    private static void findParticipants(final List<List<Integer>> adjacencyList, final List<List<Integer>> cache,
            final int current, final boolean isAttended, List<Boolean> attendance) {
        attendance.set(current, isAttended);
        for (int inferior : adjacencyList.get(current)) {
            boolean isInferiorAttended = (!isAttended && cache.get(0).get(inferior) < cache.get(1).get(inferior));
            findParticipants(adjacencyList, cache, inferior, isInferiorAttended, attendance);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuffer sb = new StringBuffer();
        StringTokenizer st;

        int num = Integer.parseInt(br.readLine());
        List<Integer> scores = new ArrayList<>(num + 1);
        List<List<Integer>> adjacencyList = new ArrayList<>(num + 1);
        List<List<Integer>> cache = new ArrayList<>(2);
        scores.add(0);
        for (int i = 0; i < 2; i++) {
            cache.add(new ArrayList<Integer>(Collections.nCopies(num + 1, 0)));
        }
        for (int i = 0; i <= num; i++) {
            adjacencyList.add(new ArrayList<Integer>());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= num; i++) {
            scores.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        for (int v = 2; v <= num; v++) {
            int u = Integer.parseInt(st.nextToken());
            adjacencyList.get(u).add(v);
        }

        calculateMaxScores(scores, adjacencyList, 1, cache);
        sb.append(cache.get(1).get(1)).append(' ').append(cache.get(0).get(1)).append('\n');
        for (boolean isAttended : List.of(true, false)) {
            List<Boolean> attendance = new ArrayList<>(Collections.nCopies(num + 1, false));
            findParticipants(adjacencyList, cache, 1, isAttended, attendance);
            for (int i = 1; i <= num; i++) {
                if (attendance.get(i)) {
                    sb.append(i).append(' ');
                }
            }
            sb.append("-1\n");
        }
        bw.write(sb.toString());
        bw.flush();

        br.close();
        bw.close();
    }
}
