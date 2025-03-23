// BOJ-06213 / Balanced Lineup
// devgeon, 2025.03.23, Java 11
// https://www.acmicpc.net/problem/6213

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static class MinMaxSegTree {
        private int size;
        private int[] tree;
        private boolean max;

        public MinMaxSegTree(int[] array, boolean max) {
            size = array.length - 1;
            tree = new int[size * 4];
            this.max = max;
            _init(array, 1, 1, size);
        }

        private int _init(int[] array, int index, int start, int end) {
            if (start == end) {
                return (this.tree[index] = array[start]);
            }
            int leftResult = _init(array, index * 2, start, (start + end) / 2);
            int rightResult = _init(array, index * 2 + 1, (start + end) / 2 + 1, end);
            this.tree[index] = (max ? Math.max(leftResult, rightResult) : Math.min(leftResult, rightResult));
            return this.tree[index];
        }

        public int query(int left, int right) {
            return _query(1, left, right, 1, size);
        }

        private int _query(int index, int left, int right, int start, int end) {
            if (right < start || end < left) {
                return (max ? Integer.MIN_VALUE : Integer.MAX_VALUE);
            }
            if (left <= start && end <= right) {
                return tree[index];
            }
            int leftResult = _query(index * 2, left, right, start, (start + end) / 2);
            int rightResult = _query(index * 2 + 1, left, right, (start + end) / 2 + 1, end);
            return (max ? Math.max(leftResult, rightResult) : Math.min(leftResult, rightResult));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalCows = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        int[] heights = new int[totalCows + 1];
        for (int i = 1; i <= totalCows; i++) {
            heights[i] = Integer.parseInt(br.readLine());
        }

        MinMaxSegTree maxSegTree = new MinMaxSegTree(heights, true);
        MinMaxSegTree minSegTree = new MinMaxSegTree(heights, false);
        for (int i = 0; i < totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            int max = maxSegTree.query(left, right);
            int min = minSegTree.query(left, right);
            bw.write(Integer.toString(max - min));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
