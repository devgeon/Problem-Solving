// BOJ-16946 / 벽 부수고 이동하기 4
// devgeon, 2025.01.28, Java 11
// https://www.acmicpc.net/problem/16946

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

class Position {
    private int row, col;

    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int getRow() {
        return this.row;
    }

    public int getCol() {
        return this.col;
    }
}

public class Main {
    private static final int[] dx = { 1, 0, -1, 0 };
    private static final int[] dy = { 0, 1, 0, -1 };

    private static void breadthFirstSearch(int[][] map, List<Integer> counts, int row, int col) {
        int key = counts.size() + 2, count = 1;
        Queue<Position> queue = new LinkedList<>();
        queue.add(new Position(row, col));
        map[row][col] = key;

        while (queue.size() > 0) {
            Position position = queue.remove();
            for (int i = 0, r = 0, c = 0; i < 4; i++) {
                r = position.getRow() + dy[i];
                c = position.getCol() + dx[i];
                if (0 <= r && r < map.length && 0 <= c && c < map[0].length && map[r][c] == 0) {
                    queue.add(new Position(r, c));
                    map[r][c] = key;
                    count++;
                }
            }
        }
        counts.add(count);
    }

    private static int countPositionsFromWall(int[][] map, List<Integer> counts, int row, int col) {
        int result = 1;
        Set<Integer> set = new HashSet<>(4);

        for (int i = 0, r = 0, c = 0; i < 4; i++) {
            r = row + dy[i];
            c = col + dx[i];
            if (0 <= r && r < map.length && 0 <= c && c < map[0].length && map[r][c] > 1) {
                set.add(map[r][c]);
            }
        }
        for (int k : set) {
            result += counts.get(k - 2);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int row = 0, col = 0;
        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());

        int[][] map = new int[row][col];
        for (int r = 0; r < row; r++) {
            String line = br.readLine();
            for (int c = 0; c < col; c++) {
                map[r][c] = (int) (line.charAt(c) - '0');
            }
        }

        List<Integer> counts = new ArrayList<>();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (map[r][c] == 0) {
                    breadthFirstSearch(map, counts, r, c);
                }
            }
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                char ch = '0';
                if (map[r][c] == 1) {
                    ch += countPositionsFromWall(map, counts, r, c) % 10;
                }
                bw.write(ch);
            }
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
