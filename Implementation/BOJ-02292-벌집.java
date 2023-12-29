// BOJ-02292 / 벌집
// devgeon, 2023.12.29, Java 11
// https://www.acmicpc.net/problem/2292

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = 0, distance = 1;

        num = Integer.parseInt(br.readLine());

        if (num == 1) {
            System.out.println(1);
            return;
        }
        while (3 * distance * (distance - 1) + 1 < num) {
            distance++;
        }

        System.out.println(distance);
    }
}
