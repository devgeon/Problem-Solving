// BOJ-02211 / 네트워크 복구
// devgeon, 2025.03.05, Java 11
// https://www.acmicpc.net/problem/2211

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    private static class Edge implements Comparable<Edge> {
        private int nodeA;
        private int nodeB;
        private int cost;

        public Edge(int nodeA, int nodeB, int cost) {
            this.nodeA = nodeA;
            this.nodeB = nodeB;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge that) {
            return Integer.compare(this.cost, that.cost);
        }

        public int getNodeA() {
            return nodeA;
        }

        public int getNodeB() {
            return nodeB;
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

        List<List<Edge>> adjList = new ArrayList<>();
        for (int i = 0; i <= totalNodes; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int i = 0; i < totalEdges; i++) {
            st = new StringTokenizer(br.readLine());
            int nodeA = Integer.parseInt(st.nextToken());
            int nodeB = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adjList.get(nodeA).add(new Edge(nodeA, nodeB, cost));
            adjList.get(nodeB).add(new Edge(nodeB, nodeA, cost));
        }

        Edge[] distance = new Edge[totalNodes + 1];
        PriorityQueue<Edge> heap = new PriorityQueue<>();
        heap.add(new Edge(0, 1, 0));
        while (!heap.isEmpty()) {
            Edge edge = heap.remove();
            int currNode = edge.getNodeB();
            int currCost = edge.getCost();
            if (distance[currNode] != null && distance[currNode].getCost() <= currCost) {
                continue;
            }
            distance[currNode] = edge;

            for (Edge next : adjList.get(currNode)) {
                int nextNode = next.getNodeB();
                int nextCost = currCost + next.getCost();
                if (distance[nextNode] != null && distance[nextNode].getCost() <= nextCost) {
                    continue;
                }
                heap.add(new Edge(currNode, nextNode, nextCost));
            }
        }

        bw.write(Integer.toString(totalNodes - 1));
        bw.newLine();
        for (int i = 2; i <= totalNodes; i++) {
            Edge edge = distance[i];
            bw.write(Integer.toString(edge.getNodeA()));
            bw.write(' ');
            bw.write(Integer.toString(edge.getNodeB()));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
