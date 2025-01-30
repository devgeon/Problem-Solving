// BOJ-02116 / 주사위 쌓기
// devgeon, 2025.01.30, Java 11
// https://www.acmicpc.net/problem/2116

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static void inputDice(BufferedReader br, List<Integer> dice) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        dice.clear();
        for (int i = 0; i < 6; i++) {
            dice.add(Integer.parseInt(st.nextToken()));
        }
    }

    private static int findTopIndex(int bottomIndex) {
        return (bottomIndex == 0 ? 5 : bottomIndex == 5 ? 0 : (bottomIndex + 1) % 4 + 1);
    }

    private static int findTopNumber(List<Integer> dice, int bottomNumber) {
        int bottomIndex = dice.indexOf(bottomNumber);
        int topIndex = findTopIndex(bottomIndex);
        return dice.get(topIndex);
    }

    private static int findMaxNumber(List<Integer> dice, int bottomNumber) {
        int bottomIndex = dice.indexOf(bottomNumber);
        int topIndex = findTopIndex(bottomIndex);

        int maxNumber = 0;
        for (int i = 0; i < 6; i++) {
            if (i == bottomIndex || i == topIndex) {
                continue;
            }
            maxNumber = Math.max(dice.get(i), maxNumber);
        }
        return maxNumber;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        List<Integer> dice = new ArrayList<>(6);
        List<List<Integer>> cache = new ArrayList<>(2);
        for (int i = 0; i < 2; i++) {
            cache.add(new ArrayList<>(Collections.nCopies(6 + 1, 0)));
        }

        for (int i = 0; i < num; i++) {
            inputDice(br, dice);
            for (int bottomNumber = 1; bottomNumber <= 6; bottomNumber++) {
                int topNumber = findTopNumber(dice, bottomNumber);
                int maxSum = cache.get((i + 1) % 2).get(bottomNumber) + findMaxNumber(dice, bottomNumber);
                cache.get(i % 2).set(topNumber, maxSum);
            }
        }

        int answer = Collections.max(cache.get((num - 1) % 2));
        bw.write(Integer.toString(answer));
        bw.flush();

        br.close();
        bw.close();
    }
}
