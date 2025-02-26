// BOJ-13702 / 이상한 술집
// devgeon, 2025.02.26, Java 11
// https://www.acmicpc.net/problem/13702

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static int count(int[] bottles, long volume) {
        int count = 0;
        for (int bottle : bottles) {
            count += bottle / volume;
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalBottles = Integer.parseInt(st.nextToken());
        int totalGlasses = Integer.parseInt(st.nextToken());

        int[] bottles = new int[totalBottles];
        for (int i = 0; i < totalBottles; i++) {
            bottles[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(bottles);

        long low = 1, high = bottles[totalBottles - 1];
        while (low <= high) {
            long mid = (low + high) >> 1;
            if (count(bottles, mid) < totalGlasses) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        bw.write(Long.toString(low - 1));
        bw.flush();

        br.close();
        bw.close();
    }
}
