// BOJ-02775 / 부녀회장이 될테야
// devgeon, 2023.12.30, Java 11
// https://www.acmicpc.net/problem/2775

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        final int FLOOR = 15, ROOM = 14;
        int cases = 0, floor = 0, room = 0;
        int[][] apartment = new int[FLOOR][ROOM];

        for (int r = 0; r < ROOM; r++) {
            apartment[0][r] = r + 1;
        }
        for (int f = 1; f < FLOOR; f++) {
            apartment[f][0] = 1;
        }
        for (int f = 1; f < FLOOR; f++) {
            for (int r = 1; r < ROOM; r++) {
                apartment[f][r] = apartment[f][r - 1] + apartment[f - 1][r];
            }
        }

        cases = Integer.parseInt(br.readLine());
        while (cases > 0) {
            floor = Integer.parseInt(br.readLine());
            room = Integer.parseInt(br.readLine()) - 1;
            sb.append(apartment[floor][room]).append('\n');
            cases--;
        }

        System.out.print(sb);
    }
}
