// BOJ-17826 / 나의 학점은?
// devgeon, 2025.03.17, Java 11
// https://www.acmicpc.net/problem/17826

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final int[] boundaries = { 0, 5, 15, 30, 35, 45, 48 };

        List<Integer> scores = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());
        int myScore = Integer.parseInt(br.readLine());

        int rank = scores.indexOf(myScore) + 1;

        for (int i = 1; i < boundaries.length; i++) {
            if (rank > boundaries[i - 1] && rank <= boundaries[i]) {
                bw.write((i - 1) / 2 + 'A');
                bw.write((i & 1) == 1 ? '+' : '0');
                break;
            }
        }
        if (rank > boundaries[boundaries.length - 1]) {
            bw.write('F');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
