// BOJ-28115 / 등차수열의 합
// devgeon, 2025.01.21, Java 11
// https://www.acmicpc.net/problem/28115

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int length = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            sequence.add(Integer.parseInt(st.nextToken()));
        }

        boolean isPossible = true;
        int difference = (length > 2 ? sequence.get(1) - sequence.get(0) : 0);
        for (int i = 2; i < length; i++) {
            if (sequence.get(i) - sequence.get(i - 1) != difference) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            bw.write("YES\n");
            for (int i = 0; i < length; i++) {
                bw.write("0 ");
            }
            bw.newLine();
            for (int n : sequence) {
                bw.write(Integer.toString(n) + " ");
            }
        } else {
            bw.write("NO");
        }
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
