// BOJ-09015 / 정사각형
// devgeon, 2025.03.25, Java 11
// https://www.acmicpc.net/problem/9015

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    private static class Point {
        private int x;
        private int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object object) {
            if (!(object instanceof Point)) {
                return false;
            }
            Point point = (Point) object;
            return x == point.getX() && y == point.getY();
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

    private static int calcSquareArea(Set<Point> points, Point a, Point b) {
        int diffX = b.getX() - a.getX();
        int diffY = b.getY() - a.getY();

        int x = b.getX(), y = b.getY();
        Point c = new Point(x - diffY, y + diffX);
        Point d = new Point(x - diffX - diffY, y + diffX - diffY);

        if (points.contains(c) && points.contains(d)) {
            return diffX * diffX + diffY * diffY;
        }
        return 0;
    }

    private static int solve(Set<Point> points) {
        int answer = 0;
        for (Point base : points) {
            for (Point other : points) {
                if (base == other) {
                    continue;
                }
                int area = calcSquareArea(points, base, other);
                answer = Math.max(area, answer);
            }
        }
        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalCases = Integer.parseInt(br.readLine());

        for (int i = 0; i < totalCases; i++) {
            int num = Integer.parseInt(br.readLine());

            Set<Point> points = new HashSet<>(num << 1);
            for (int j = 0; j < num; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                points.add(new Point(x, y));
            }

            int answer = solve(points);
            bw.write(Integer.toString(answer));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
