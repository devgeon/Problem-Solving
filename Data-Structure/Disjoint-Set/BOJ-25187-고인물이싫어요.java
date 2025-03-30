// BOJ-25187 / 고인물이 싫어요
// devgeon, 2025.03.28, Java 11
// https://www.acmicpc.net/problem/25187

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

class DisjointSet {
    private int[] roots;

    public DisjointSet(final int size) {
        roots = new int[size + 1];
        for (int i = 1; i <= size; i++) {
            roots[i] = i;
        }
    }

    public int find(final int num) {
        if (roots[num] == num) {
            return num;
        }
        return (roots[num] = find(roots[num]));
    }

    public void union(final int a, final int b) {
        int rootA = find(a), rootB = find(b);
        if (rootA != rootB) {
            roots[rootA] = rootB;
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalTanks = Integer.parseInt(st.nextToken());
        int totalPipes = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        boolean[] cleanTanks = new boolean[totalTanks + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= totalTanks; i++) {
            cleanTanks[i] = (st.nextToken().charAt(0) == '1');
        }

        DisjointSet disjointSet = new DisjointSet(totalTanks);
        for (int i = 1; i <= totalPipes; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            disjointSet.union(a, b);
        }

        Map<Integer, Integer> cleanScore = new HashMap<>();
        for (int i = 1; i <= totalTanks; i++) {
            int key = disjointSet.find(i);
            int value = (cleanTanks[i] ? 1 : -1);
            if (cleanScore.containsKey(key)) {
                value += cleanScore.get(key);
            }
            cleanScore.put(key, value);
        }

        for (int i = 1; i <= totalQueries; i++) {
            int num = Integer.parseInt(br.readLine());
            int key = disjointSet.find(num);
            char answer = (cleanScore.get(key) > 0 ? '1' : '0');
            bw.write(answer);
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
