// BOJ-06059 / Pasture Walking
// devgeon, 2025.02.07, Java 11
// https://www.acmicpc.net/problem/6059

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static class Edge {
        private int dest;
        private int cost;

        public Edge(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }

        public int getDest() {
            return dest;
        }

        public int getCost() {
            return cost;
        }
    }

    private static int dfs(final List<List<Edge>> adjacentList, final int curr, final int dest, final int prev) {
        if (curr == dest) {
            return 0;
        }
        for (Edge edge : adjacentList.get(curr)) {
            int next = edge.getDest();
            if (next == prev) {
                continue;
            }
            int result = dfs(adjacentList, next, dest, curr);
            if (result >= 0) {
                return result + edge.getCost();
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalNodes = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        List<List<Edge>> adjacentList = new ArrayList<>(totalNodes + 1);
        for (int i = 0; i <= totalNodes; i++) {
            adjacentList.add(new ArrayList<>());
        }
        for (int i = 1; i < totalNodes; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adjacentList.get(u).add(new Edge(v, cost));
            adjacentList.get(v).add(new Edge(u, cost));
        }

        for (int i = 0; i < totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int answer = dfs(adjacentList, u, v, -1);
            bw.write(Integer.toString(answer));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
