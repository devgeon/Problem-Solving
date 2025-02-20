// BOJ-01647 / 도시 분할 계획
// devgeon, 2025.02.20, Java 11
// https://www.acmicpc.net/problem/1647

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static class Edge implements Comparable<Edge> {
        private int from;
        private int to;
        private int cost;

        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(cost, other.getCost());
        }

        public int getFrom() {
            return from;
        }

        public int getTo() {
            return to;
        }

        public int getCost() {
            return cost;
        }
    }

    private static class DisjointSet {
        private int[] roots;

        DisjointSet(int size) {
            roots = new int[size + 1];
            for (int i = 1; i <= size; i++) {
                roots[i] = i;
            }
        }

        public int find(int index) {
            if (index == roots[index]) {
                return index;
            }
            return (roots[index] = find(roots[index]));
        }

        public boolean union(int indexA, int indexB) {
            int rootA = find(indexA), rootB = find(indexB);
            if (rootA != rootB) {
                roots[rootB] = rootA;
                return true;
            }
            return false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalNodes = Integer.parseInt(st.nextToken());
        int totalEdges = Integer.parseInt(st.nextToken());

        Edge[] edges = new Edge[totalEdges];
        for (int i = 0; i < totalEdges; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            edges[i] = new Edge(from, to, cost);
        }
        Arrays.sort(edges);

        int count = 0, answer = 0;
        DisjointSet disjointSet = new DisjointSet(totalNodes);
        for (int i = 0; count < totalNodes - 2; i++) {
            Edge edge = edges[i];
            if (disjointSet.union(edge.getFrom(), edge.getTo())) {
                answer += edge.getCost();
                count++;
            }
        }
        System.out.println(answer);

        br.close();
    }
}
