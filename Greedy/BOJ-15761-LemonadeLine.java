// BOJ-15761 / Lemonade Line
// devgeon, 2024.09.09, Java 11
// https://www.acmicpc.net/problem/15761

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = 0, answer = 0;

        num = Integer.parseInt(br.readLine());
        List<Integer> patiences = new ArrayList<>(num);
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < num; i++) {
            patiences.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(patiences, Collections.reverseOrder());

        for (int n : patiences) {
            if (n < answer) {
                break;
            }
            answer++;
        }

        bw.write(String.valueOf(answer));
        bw.newLine();

        br.close();
        bw.close();
    }

}
