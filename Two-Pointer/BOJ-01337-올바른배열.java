// BOJ-01337 / 올바른 배열
// devgeon, 2024.09.15, Java 11
// https://www.acmicpc.net/problem/1337

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

        final int MAX = 1_000_000_000;
        int num = 0, answer = 0;
        int max_len = 0, min_diff = MAX;
        List<Integer> seq = new ArrayList<>(num);

        num = Integer.parseInt(br.readLine());
        for (int i = 0; i < num; i++) {
            seq.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(seq);

        for (int i = 1, sum = 0, len = 0, diff = 0; i < num; i++) {
            sum += seq.get(i) - seq.get(i - 1);
            len++;
            diff = Math.abs(sum - 4);
            if (diff < min_diff || diff == min_diff && (sum < 4 || len > max_len)) {
                min_diff = diff;
                max_len = sum < 4 ? 4 : len;
            }
            while (sum >= 4) {
                sum -= seq.get(i - len + 1) - seq.get(i - len);
                len--;
            }
        }

        answer = Math.min(min_diff - max_len + 4, 4);

        bw.write(String.valueOf(answer));
        bw.newLine();

        br.close();
        bw.close();
    }

}
