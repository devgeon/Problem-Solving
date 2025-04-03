// BOJ-11811 / 데스스타
// devgeon, 2025.04.02, Java 11
// https://www.acmicpc.net/problem/11811

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = Integer.parseInt(br.readLine());
        int[] sequence = new int[size];

        for (int i = 0; i < size; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < size; j++) {
                int element = Integer.parseInt(st.nextToken());
                if (i == j) {
                    continue;
                }
                sequence[i] |= element;
                sequence[j] |= element;
            }
        }

        for (int num : sequence) {
            bw.write(Integer.toString(num));
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
