// BOJ-01895 / 필터
// devgeon, 2025.01.27, Java 11
// https://www.acmicpc.net/problem/1895

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int row = 0, col = 0;
        int threshold = 0, answer = 0;
        int[][] image = new int[40][40];
        ArrayList<Integer> filterInput = new ArrayList<>();

        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());
        for (int r = 0; r < row; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < col; c++) {
                image[r][c] = Integer.parseInt(st.nextToken());
            }
        }
        threshold = Integer.parseInt(br.readLine());

        for (int r = 2; r < row; r++) {
            for (int c = 2; c < col; c++) {
                filterInput.clear();
                for (int i = r - 2; i <= r; i++) {
                    for (int j = c - 2; j <= c; j++) {
                        filterInput.add(image[i][j]);
                    }
                }
                filterInput.sort(Comparator.naturalOrder());

                if (filterInput.get(filterInput.size() / 2) >= threshold) {
                    answer++;
                }
            }
        }

        bw.write(Integer.toString(answer));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
