// BOJ-12913 / 매직 포션
// devgeon, 2025.02.16, Java 11
// https://www.acmicpc.net/problem/12913

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    private static class Element implements Comparable<Element> {
        private double cost;
        private int node;
        private int numOfPotions;

        public Element(double cost, int node, int numOfPotions) {
            this.cost = cost;
            this.node = node;
            this.numOfPotions = numOfPotions;
        }

        public double getCost() {
            return cost;
        }

        public int getNode() {
            return node;
        }

        public int getNumOfPotions() {
            return numOfPotions;
        }

        @Override
        public int compareTo(Element element) {
            return Double.compare(cost, element.getCost());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int numOfCities = Integer.parseInt(st.nextToken());
        int numOfPotions = Integer.parseInt(st.nextToken());

        int[][] distances = new int[numOfCities][numOfCities];
        for (int r = 0; r < numOfCities; r++) {
            String row = br.readLine();
            for (int c = 0; c < numOfCities; c++) {
                distances[r][c] = row.charAt(c) - '0';
            }
        }

        double[][] shortestPaths = new double[numOfCities][numOfPotions + 1];
        for (int i = 0; i < numOfCities; i++) {
            for (int j = 0; j <= numOfPotions; j++) {
                shortestPaths[i][j] = Double.MAX_VALUE;
            }
        }

        PriorityQueue<Element> heap = new PriorityQueue<>();
        heap.add(new Element(0, 0, numOfPotions));
        while (!heap.isEmpty()) {
            Element top = heap.remove();
            double cost = top.getCost();
            int curr = top.getNode();
            int potions = top.getNumOfPotions();
            for (int next = 0; next < numOfCities; next++) {
                if (curr == next) {
                    continue;
                }
                if (cost + distances[curr][next] < shortestPaths[next][potions]) {
                    shortestPaths[next][potions] = cost + distances[curr][next];
                    heap.add(new Element(shortestPaths[next][potions], next, potions));
                }
                if (potions > 0 && cost + (double) distances[curr][next] / 2 < shortestPaths[next][potions - 1]) {
                    shortestPaths[next][potions - 1] = cost + (double) distances[curr][next] / 2;
                    heap.add(new Element(shortestPaths[next][potions - 1], next, potions - 1));
                }
            }
        }

        double answer = Double.MAX_VALUE;
        for (int i = 0; i <= numOfPotions; i++) {
            answer = Math.min(answer, shortestPaths[1][i]);
        }
        System.out.println(answer);

        br.close();
    }
}
