// BOJ-23081 / 오델로
// devgeon, 2025.03.01, Java 11
// https://www.acmicpc.net/problem/23081

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static final int[] DX = { 1, 1, 0, -1, -1, -1, 0, 1 };
    private static final int[] DY = { 0, -1, -1, -1, 0, 1, 1, 1 };

    private static enum Disk {
        Blank,
        Black,
        White
    }

    private static class Othello {
        private Disk[][] board;

        public Othello(int size) {
            board = new Disk[size][size];
            for (int y = 0; y < size; y++) {
                for (int x = 0; x < size; x++) {
                    board[y][x] = Disk.Blank;
                }
            }
        }

        public boolean placeDisk(int x, int y, Disk disk) {
            if (board[y][x] != Disk.Blank) {
                return false;
            }
            board[y][x] = disk;
            return true;
        }

        public int countFlips(int x, int y, Disk disk) {
            if (board[y][x] != Disk.Blank) {
                return 0;
            }

            int total = 0;
            for (int i = 0; i < DX.length; i++) {
                int count = 0;
                for (int nx = x + DX[i], ny = y + DY[i]; 0 <= nx && nx < board.length && 0 <= ny
                        && ny < board.length; nx += DX[i], ny += DY[i]) {
                    if (board[ny][nx] == Disk.Blank) {
                        break;
                    }
                    if (board[ny][nx] == disk) {
                        total += count;
                        break;
                    }
                    count++;
                }
            }
            return total;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int size = Integer.parseInt(br.readLine());
        Othello board = new Othello(size);
        for (int y = 0; y < size; y++) {
            String line = br.readLine();
            for (int x = 0; x < size; x++) {
                char input = line.charAt(x);
                Disk disk = (input == '.' ? Disk.Blank : (input == 'B' ? Disk.Black : Disk.White));
                board.placeDisk(x, y, disk);
            }
        }

        int maxX = 0, maxY = 0, maxCount = 0;
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                int count = board.countFlips(x, y, Disk.Black);
                if (count > maxCount) {
                    maxCount = count;
                    maxX = x;
                    maxY = y;
                }
            }
        }

        if (maxCount == 0) {
            bw.write("PASS");
        } else {
            bw.write(Integer.toString(maxX));
            bw.write(' ');
            bw.write(Integer.toString(maxY));
            bw.newLine();
            bw.write(Integer.toString(maxCount));
        }
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
