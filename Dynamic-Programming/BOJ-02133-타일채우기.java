// BOJ-02133 / 타일 채우기
// devgeon, 2024.09.20, Java 11
// https://www.acmicpc.net/problem/2133

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        boolean isEven = num % 2 == 0;
        num /= 2;

        List<Integer> cache = new ArrayList<>(3);
        Collections.addAll(cache, 1, 3, 0);

        for (int i = 2; i <= num; i++) {
            cache.set(i % 3, cache.get((i + 2) % 3) * 4 - cache.get((i + 1) % 3));
        }

        bw.write(String.valueOf(isEven ? cache.get(num % 3) : 0));
        bw.newLine();

        br.close();
        bw.close();
    }

}
