// BOJ-01476 / 날짜 계산
// devgeon, 2025.02.17, Java 11
// https://www.acmicpc.net/problem/1476

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int targetEarth = sc.nextInt();
        int targetSun = sc.nextInt();
        int targetMoon = sc.nextInt();
        int earth = 1, sun = 1, moon = 1, year = 1;

        while (earth != targetEarth || sun != targetSun || moon != targetMoon) {
            earth = (earth) % 15 + 1;
            sun = (sun) % 28 + 1;
            moon = (moon) % 19 + 1;
            year++;
        }
        System.out.println(year);

        sc.close();
    }
}
