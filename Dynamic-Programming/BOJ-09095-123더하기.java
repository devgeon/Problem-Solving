// BOJ-09095 / 1, 2, 3 더하기
// devgeon, 2024.09.21, Java 11
// https://www.acmicpc.net/problem/9095

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int MAX = 10;
        int cases = 0, num = 0;
        cases = Integer.parseInt(br.readLine());

        List<Integer> cache = new ArrayList<>(MAX);
        Collections.addAll(cache, 1, 2, 4);
        for (int i = 3; i < MAX; i++) {
            cache.add(cache.get(i - 1) + cache.get(i - 2) + cache.get(i - 3));
        }

        while (cases-- > 0) {
            num = Integer.parseInt(br.readLine());
            bw.write(String.valueOf(cache.get(num - 1)));
            bw.write('\n');
        }
        bw.flush();

        br.close();
        bw.close();
    }

}
