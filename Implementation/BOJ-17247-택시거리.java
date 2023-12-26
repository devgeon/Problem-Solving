// BOJ-17247 / 택시 거리
// devgeon, 2023.12.26, Java 11
// https://www.acmicpc.net/problem/17247

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int row = 0, col = 0, input = 0, distance = 0;
        int first_r = -1, first_c = -1, second_r = -1, second_c = -1;
        StringTokenizer st;
        try {
            st = new StringTokenizer(br.readLine());
        } catch (IOException error) {
            System.err.println(error);
            return;
        }
        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());

        for (int r = 0; r < row; r++) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException error) {
                System.err.println(error);
                return;
            }
            for (int c = 0; c < col; c++) {
                input = Integer.parseInt(st.nextToken());
                if (input == 0) {
                    continue;
                }
                if (first_r == -1) {
                    first_r = r;
                    first_c = c;
                } else {
                    second_r = r;
                    second_c = c;
                    r = row;
                    break;
                }
            }
        }

        distance = second_c - first_c;
        if (distance < 0) {
            distance *= -1;
        }
        distance += second_r - first_r;

        System.out.println(distance);
    }
}
