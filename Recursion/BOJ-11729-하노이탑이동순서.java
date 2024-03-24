// BOJ-11729 / 하노이 탑 이동 순서
// devgeon, 2024.03.24, Java 11
// https://www.acmicpc.net/problem/11729

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    private static BufferedReader br;
    private static BufferedWriter bw;

    public static void main(String[] args) throws IOException {
        int num = 0;

        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        num = Integer.parseInt(br.readLine());

        bw.write(String.valueOf((int) Math.pow(2, num) - 1));
        bw.write('\n');

        hanoi(num, 1, 3, 2);

        bw.flush();
        br.close();
        bw.close();
    }

    private static void move(int from, int to) throws IOException {
        bw.write(String.valueOf(from));
        bw.write(' ');
        bw.write(String.valueOf(to));
        bw.write('\n');
    }

    private static void hanoi(int num, int from, int to, int temp) throws IOException {
        if (num == 1) {
            move(from, to);
            return;
        }

        hanoi(num - 1, from, temp, to);
        move(from, to);
        hanoi(num - 1, temp, to, from);
    }
}
