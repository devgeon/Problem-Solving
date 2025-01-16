// BOJ-17877 / Integer Division
// devgeon, 2025.01.16, Java 11
// https://www.acmicpc.net/problem/17877

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int num = 0, divisor = 0;
        long count = 0;
        num = Integer.parseInt(st.nextToken());
        divisor = Integer.parseInt(st.nextToken());

        HashMap<Integer, Integer> counter = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0, key = 0; i < num; i++) {
            key = Integer.parseInt(st.nextToken()) / divisor;
            Integer cnt = counter.get(key);
            cnt = (cnt == null ? 1 : cnt + 1);
            counter.put(key, cnt);
        }

        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            long cnt = entry.getValue();
            count += cnt * (cnt - 1) / 2;
        }
        bw.write(Long.toString(count));
        bw.flush();

        br.close();
        bw.close();
    }
}
