// BOJ-09879 / Cross Country Skiing
// devgeon, 2025.02.06, Java 11
// https://www.acmicpc.net/problem/9879

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    private static class Edge implements Comparable<Edge> {
        private int cost;
        private int row;
        private int col;

        public Edge(final int cost, final int row, final int col) {
            this.cost = cost;
            this.row = row;
            this.col = col;
        }

        public int getCost() {
            return cost;
        }

        public int getRow() {
            return row;
        }

        public int getCol() {
            return col;
        }

        @Override
        public int compareTo(Edge that) {
            return Integer.compare(this.cost, that.cost);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        final int[] DIFF_ROW = { 0, -1, 0, 1 };
        final int[] DIFF_COL = { 1, 0, -1, 0 };

        int rowSize = Integer.parseInt(st.nextToken());
        int colSize = Integer.parseInt(st.nextToken());

        int[][] elevations = new int[rowSize][colSize];
        for (int row = 0; row < rowSize; row++) {
            st = new StringTokenizer(br.readLine());
            for (int col = 0; col < colSize; col++) {
                elevations[row][col] = Integer.parseInt(st.nextToken());
            }
        }

        int left = 0, startRow = -1, startCol = -1;
        boolean[][] waypoints = new boolean[rowSize][colSize];
        for (int row = 0; row < rowSize; row++) {
            st = new StringTokenizer(br.readLine());
            for (int col = 0; col < colSize; col++) {
                if (st.nextToken().equals("1")) {
                    waypoints[row][col] = true;
                    startRow = row;
                    startCol = col;
                    left++;
                }
            }
        }

        int answer = 0;
        boolean[][] visited = new boolean[rowSize][colSize];
        PriorityQueue<Edge> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new Edge(0, startRow, startCol));

        while (left > 0) {
            Edge edge = priorityQueue.remove();
            int row = edge.getRow(), col = edge.getCol();
            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            for (int i = 0; i < DIFF_ROW.length; i++) {
                int r = row + DIFF_ROW[i], c = col + DIFF_COL[i];
                if (0 <= r && r < rowSize && 0 <= c && c < colSize) {
                    int cost = Math.abs(elevations[row][col] - elevations[r][c]);
                    priorityQueue.add(new Edge(cost, r, c));
                }
            }

            if (waypoints[row][col]) {
                left--;
            }
            answer = Math.max(answer, edge.getCost());
        }

        bw.write(Integer.toString(answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
