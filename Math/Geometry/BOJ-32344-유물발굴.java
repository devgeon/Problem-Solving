// BOJ-32344 / 유물 발굴
// devgeon, 2025.02.28, Java 11
// https://www.acmicpc.net/problem/32344

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static class Pieces implements Comparable<Pieces> {
        private int top = Integer.MAX_VALUE;
        private int bottom = 0;
        private int left = Integer.MAX_VALUE;
        private int right = 0;
        private Long area = null;

        public void update(int row, int col) {
            top = Math.min(top, row);
            bottom = Math.max(bottom, row);
            left = Math.min(left, col);
            right = Math.max(right, col);
            area = null;
        }

        public long getArea() {
            if (area == null) {
                area = (long) (bottom - top + 1) * (right - left + 1);
            }
            return area;
        }

        @Override
        public int compareTo(Pieces that) {
            return Long.compare(this.getArea(), that.getArea());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br.readLine();

        int totalPieces = Integer.parseInt(br.readLine());
        Pieces[] piecesArray = new Pieces[totalPieces + 1];
        for (int i = 1; i <= totalPieces; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            if (piecesArray[num] == null) {
                piecesArray[num] = new Pieces();
            }
            piecesArray[num].update(row, col);
        }

        int maxIndex = 0;
        Pieces maxPieces = null;
        for (int i = 1; i <= totalPieces; i++) {
            if (piecesArray[i] == null) {
                continue;
            }
            if (maxPieces == null || maxPieces.compareTo(piecesArray[i]) < 0) {
                maxIndex = i;
                maxPieces = piecesArray[i];
            }
        }

        bw.write(Integer.toString(maxIndex));
        bw.write(' ');
        bw.write(Long.toString(maxPieces.getArea()));
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
