// BOJ-02042 / 구간 합 구하기
// devgeon, 2025.01.27, Java 11
// https://www.acmicpc.net/problem/2042

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class SegmentTree {
    private int size;
    private ArrayList<Long> tree;

    public SegmentTree(List<Long> list) {
        this.size = list.size() - 1;
        int height = (int) Math.ceil(Math.log(this.size) / Math.log(2));
        this.tree = new ArrayList<>(Collections.nCopies(1 << (height + 1), 0L));
        _init(list, 1, 1, this.size);
    }

    private long _init(List<Long> list, int node, int start, int end) {
        if (start == end) {
            this.tree.set(node, list.get(start));
            return this.tree.get(node);
        }
        long leftSum = _init(list, node * 2, start, (start + end) / 2);
        long rightSum = _init(list, node * 2 + 1, (start + end) / 2 + 1, end);
        this.tree.set(node, leftSum + rightSum);
        return this.tree.get(node);
    }

    public long query(int left, int right) {
        return _query(1, left, right, 1, this.size);
    }

    private long _query(int node, int left, int right, int start, int end) {
        if (right < start || end < left) {
            return 0L;
        }
        if (left <= start && end <= right) {
            return this.tree.get(node);
        }
        long result = _query(node * 2, left, right, start, (start + end) / 2);
        result += _query(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
        return result;
    }

    public void update(int index, long value) {
        _update(1, 1, this.size, index, value);
    }

    private long _update(int node, int start, int end, int index, long value) {
        if (index < start || end < index) {
            return 0L;
        }
        if (start == end) {
            long diff = value - this.tree.get(node);
            this.tree.set(node, value);
            return diff;
        }
        long diff = _update(node * 2, start, (start + end) / 2, index, value);
        diff += _update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
        this.tree.set(node, this.tree.get(node) + diff);
        return diff;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalNumbers = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());

        ArrayList<Long> list = new ArrayList<>();
        list.add(0L);
        for (int i = 0; i < totalNumbers; i++) {
            list.add(Long.parseLong(br.readLine()));
        }

        SegmentTree segmentTree = new SegmentTree(list);
        for (int i = 0; i < totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            int operationType = Integer.parseInt(st.nextToken());
            if (operationType == 1) {
                int index = Integer.parseInt(st.nextToken());
                long value = Long.parseLong(st.nextToken());
                segmentTree.update(index, value);
            } else {
                int left = Integer.parseInt(st.nextToken());
                int right = Integer.parseInt(st.nextToken());
                long result = segmentTree.query(left, right);
                bw.write(Long.toString(result));
                bw.newLine();
            }
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
