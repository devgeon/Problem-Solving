// BOJ-31883 / FA수의 진
// devgeon, 2024.09.16, Java 11
// https://www.acmicpc.net/problem/31883

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
        StringTokenizer st;

        int num = 0, cross = 0, bridge = 0, green = 0, red = 0;
        int cycle = 0, time = 0, nextGreen = 0;

        num = Integer.parseInt(br.readLine());

        for (int i = 0; i < num; i++) {
            st = new StringTokenizer(br.readLine());

            cross = Integer.parseInt(st.nextToken());
            bridge = Integer.parseInt(st.nextToken());
            green = Integer.parseInt(st.nextToken());
            red = Integer.parseInt(st.nextToken());

            cycle = red + green;
            nextGreen = cycle - time % cycle;

            if (cycle - nextGreen < green) {
                time += cross;
            } else if (nextGreen + cross < bridge) {
                time += nextGreen + cross;
            } else {
                time += bridge;
            }
        }

        bw.write(String.valueOf(time));
        bw.newLine();

        br.close();
        bw.close();
    }

}
