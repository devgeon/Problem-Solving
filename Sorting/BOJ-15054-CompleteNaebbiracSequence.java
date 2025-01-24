// BOJ-15054 / Complete Naebbirac’s sequence
// devgeon, 2025.01.24, Java 11
// https://www.acmicpc.net/problem/15054

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static String solve(List<Integer> indexes, List<Integer> counter, int max_num) {
        int count = counter.get(indexes.get(1));
        for (int i = 2; i < max_num - 1; i++) {
            if (counter.get(indexes.get(i)) != count) {
                return "*";
            }
        }

        if (counter.get(indexes.get(0)) == count - 1 &&
                counter.get(indexes.get(max_num - 1)) == count) {
            return "+" + (indexes.get(0) + 1);
        } else if (counter.get(indexes.get(0)) == count &&
                counter.get(indexes.get(max_num - 1)) == count + 1) {
            return "-" + (indexes.get(max_num - 1) + 1);
        } else if (counter.get(indexes.get(0)) == count - 1 &&
                counter.get(indexes.get(max_num - 1)) == count + 1) {
            return String.format("-%d +%d", indexes.get(max_num - 1) + 1, indexes.get(0) + 1);
        } else {
            return "*";
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int max_num = 0, length = 0;
        max_num = Integer.parseInt(st.nextToken());
        length = Integer.parseInt(st.nextToken());

        List<Integer> indexes = new ArrayList<>();
        List<Integer> counter = new ArrayList<>();
        for (int i = 0; i < max_num; i++) {
            indexes.add(i);
            counter.add(0);
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < length; i++) {
            int index = Integer.parseInt(st.nextToken()) - 1;
            counter.set(index, counter.get(index) + 1);
        }
        indexes.sort(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return counter.get(a) - counter.get(b);
            }
        });

        bw.write(solve(indexes, counter, max_num));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
