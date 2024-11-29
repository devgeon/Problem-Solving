// BOJ-32403 / 전구 주기 맞추기
// devgeon, 2024.11.29, Java 11
// https://www.acmicpc.net/problem/32403

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int num = Integer.parseInt(st.nextToken());
        int time = Integer.parseInt(st.nextToken());
        int answer = 0;

        ArrayList<Integer> factors = new ArrayList<>();
        for (int i = 1; i * i <= time; i++) {
            if (time % i == 0) {
                factors.add(i);
                if (i * i != time)
                    factors.add(time / i);
            }
        }
        Collections.sort(factors);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {
            int period = Integer.parseInt(st.nextToken());
            int index = Collections.binarySearch(factors, period);
            if (period > time) {
                answer += period - time;
            } else if (index < 0) {
                int upper = factors.get(Math.min(-index - 1, factors.size() - 1));
                int lower = factors.get(Math.max(-index - 2, 0));
                answer += Math.min(upper - period, period - lower);
            }
        }

        bw.write(Integer.toString(answer));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
