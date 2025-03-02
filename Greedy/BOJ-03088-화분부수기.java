// BOJ-03088 / 화분 부수기
// devgeon, 2025.03.02, Java 11
// https://www.acmicpc.net/problem/3088

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalPots = Integer.parseInt(br.readLine());

        int answer = 0;
        BitSet bitset = new BitSet(1_000_000);
        for (int i = 0; i < totalPots; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (!bitset.get(a) && !bitset.get(b) && !bitset.get(c)) {
                answer++;
            }
            bitset.set(a);
            bitset.set(b);
            bitset.set(c);
        }

        bw.write(Integer.toString(answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
