// BOJ-25966 / 배찬우는 배열을 좋아해
// devgeon, 2025.04.09, Java 11
// https://www.acmicpc.net/problem/25966

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int rowSize = Integer.parseInt(st.nextToken());
        int colSize = Integer.parseInt(st.nextToken());
        int totalQueries = Integer.parseInt(st.nextToken());

        List<List<Integer>> list = new ArrayList<>(rowSize);
        for (int i = 0; i < rowSize; i++) {
            list.add(new ArrayList<>(colSize));
        }
        for (int r = 0; r < rowSize; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < colSize; c++) {
                list.get(r).add(Integer.parseInt(st.nextToken()));
            }
        }

        for (int i = 0; i < totalQueries; i++) {
            st = new StringTokenizer(br.readLine());
            if (st.nextToken().equals("0")) {
                int row = Integer.parseInt(st.nextToken());
                int col = Integer.parseInt(st.nextToken());
                int num = Integer.parseInt(st.nextToken());
                list.get(row).set(col, num);
            } else {
                int row1 = Integer.parseInt(st.nextToken());
                int row2 = Integer.parseInt(st.nextToken());
                List<Integer> tempRow = list.get(row1);
                list.set(row1, list.get(row2));
                list.set(row2, tempRow);
            }
        }

        for (List<Integer> row : list) {
            for (Integer num : row) {
                bw.write(Integer.toString(num));
                bw.write(' ');
            }
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
