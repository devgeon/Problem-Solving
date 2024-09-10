// BOJ-09657 / 돌 게임 3
// devgeon, 2024.09.10, Java 11
// https://www.acmicpc.net/problem/9657

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

        int num = 0;
        boolean isWinnable = false;

        num = Integer.parseInt(br.readLine());
        List<Boolean> cache = new ArrayList<>(num);
        Collections.addAll(cache, true, false, true, true);

        for (int i = 4; i < num; i++) {
            isWinnable = true;
            for (int d : List.of(1, 3, 4)) {
                if (i - d < 0) {
                    break;
                }
                isWinnable = isWinnable && cache.get(i - d);
            }
            cache.add(!isWinnable);
        }

        bw.write(cache.get(num - 1) ? "SK" : "CY");
        bw.newLine();

        br.close();
        bw.close();
    }

}
