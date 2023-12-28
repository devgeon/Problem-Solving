// BOJ-02869 / 달팽이는 올라가고 싶다
// devgeon, 2023.12.28, Java 11
// https://www.acmicpc.net/problem/2869

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int climb = 0, slip = 0, goal = 0, day = 0;

        climb = Integer.parseInt(st.nextToken());
        slip = Integer.parseInt(st.nextToken());
        goal = Integer.parseInt(st.nextToken());

        if (climb == goal) {
            day = 1;
        } else {
            day = (goal - climb - 1) / (climb - slip) + 2;
        }

        System.out.println(day);
    }
}
