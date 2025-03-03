// BOJ-01652 / 누울 자리를 찾아라
// devgeon, 2025.03.03, Java 11
// https://www.acmicpc.net/problem/1652

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = Integer.parseInt(br.readLine());
        boolean[][] room = new boolean[size][size];
        for (int r = 0; r < size; r++) {
            String line = br.readLine();
            for (int c = 0; c < size; c++) {
                room[r][c] = (line.charAt(c) == '.');
            }
        }

        int rowCount = 0;
        for (int r = 0; r < size; r++) {
            int length = 0;
            for (int c = 0; c < size; c++) {
                if (room[r][c]) {
                    length++;
                    continue;
                }
                if (length >= 2) {
                    rowCount++;
                }
                length = 0;
            }
            if (length >= 2) {
                rowCount++;
            }
        }

        int colCount = 0;
        for (int c = 0; c < size; c++) {
            int length = 0;
            for (int r = 0; r < size; r++) {
                if (room[r][c]) {
                    length++;
                    continue;
                }
                if (length >= 2) {
                    colCount++;
                }
                length = 0;
            }
            if (length >= 2) {
                colCount++;
            }
        }

        bw.write(Integer.toString(rowCount));
        bw.write(' ');
        bw.write(Integer.toString(colCount));
        bw.flush();

        br.close();
        bw.close();
    }
}
