// BOJ-01854 / K번째 최단경로 찾기
// devgeon, 2025.03.10, Java 11
// https://www.acmicpc.net/problem/1854

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    private static class Edge implements Comparable<Edge> {
        private int dest = 0;
        private int cost = 0;

        public Edge(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge that) {
            return Integer.compare(this.cost, that.cost);
        }

        public int getDest() {
            return dest;
        }

        public int getCost() {
            return cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalNodes = Integer.parseInt(st.nextToken());
        int totalEdges = Integer.parseInt(st.nextToken());
        int kTh = Integer.parseInt(st.nextToken());

        List<List<Edge>> adjList = new ArrayList<>();
        for (int i = 0; i <= totalNodes; i++) {
            adjList.add(new ArrayList<>());
        }

        for (int i = 1; i <= totalEdges; i++) {
            st = new StringTokenizer(br.readLine());
            int dept = Integer.parseInt(st.nextToken());
            int dest = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adjList.get(dept).add(new Edge(dest, cost));
        }

        PriorityQueue<Edge> heap = new PriorityQueue<>();
        heap.add(new Edge(1, 0));
        List<PriorityQueue<Integer>> distHeapList = new ArrayList<>();
        for (int i = 0; i <= totalNodes; i++) {
            distHeapList.add(new PriorityQueue<>(Collections.reverseOrder()));
        }
        distHeapList.get(1).add(0);

        while (!heap.isEmpty()) {
            Edge edge = heap.remove();
            int dest = edge.getDest();
            int cost = edge.getCost();
            for (Edge newEdge : adjList.get(dest)) {
                int newDest = newEdge.getDest();
                int newCost = cost + newEdge.getCost();
                PriorityQueue<Integer> distHeap = distHeapList.get(newDest);
                if (distHeap.size() == kTh) {
                    if (distHeap.element() <= newCost) {
                        continue;
                    }
                    distHeap.remove();
                }
                distHeap.add(newCost);
                heap.add(new Edge(newDest, newCost));
            }
        }

        for (int i = 1; i <= totalNodes; i++) {
            PriorityQueue<Integer> distHeap = distHeapList.get(i);
            if (distHeap.size() < kTh) {
                bw.write("-1");
            } else {
                bw.write(Integer.toString(distHeap.element()));
            }
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
