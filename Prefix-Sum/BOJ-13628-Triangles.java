// BOJ-13628 / Triangles
// devgeon, 2025.02.08, Java 11
// https://www.acmicpc.net/problem/13628

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.util.Collections.binarySearch;

public class Main {
    private static int solve(final List<Integer> prefixSum, final int totalLength) {
        if (totalLength % 3 != 0) {
            return 0;
        }

        int count = 0;
        int difference = totalLength / 3;
        for (int i = 0, curr = 0; (curr = prefixSum.get(i)) < difference; i++) {
            if (binarySearch(prefixSum, curr + difference) >= 0
                && binarySearch(prefixSum, curr + (difference << 1)) >= 0) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int totalPoints = Integer.parseInt(br.readLine());
        int totalLength = 0;

        List<Integer> prefixSum = new ArrayList<>(totalPoints);
        prefixSum.add(0);
        st = new StringTokenizer(br.readLine());
        for (int i = 1, curr = 0, prev = 0; i < totalPoints; i++) {
            curr = Integer.parseInt(st.nextToken());
            totalLength += curr;
            prefixSum.add(curr + prev);
            prev = curr + prev;
        }
        totalLength += Integer.parseInt(st.nextToken());

        System.out.println(solve(prefixSum, totalLength));

        br.close();
    }
}
