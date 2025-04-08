// BOJ-25955 / APC는 쉬운 난이도 순일까, 아닐까?
// devgeon, 2025.04.08, Java 11
// https://www.acmicpc.net/problem/25955

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    private static enum Tier {
        BRONZE, SILVER, GOLD, PLATINUM, DIAMOND
    }

    private static final Map<Character, Tier> TIER_MAP = Map.of(
            'B', Tier.BRONZE,
            'S', Tier.SILVER,
            'G', Tier.GOLD,
            'P', Tier.PLATINUM,
            'D', Tier.DIAMOND);

    private static class DifficultyComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            Tier tierA = TIER_MAP.get(a.charAt(0));
            Tier tierB = TIER_MAP.get(b.charAt(0));
            int result = tierA.compareTo(tierB);
            if (result == 0) {
                int levelA = Integer.parseInt(a.substring(1));
                int levelB = Integer.parseInt(b.substring(1));
                result = Integer.compare(levelB, levelA);
            }
            return result;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());

        List<String> difficulties = new ArrayList<>(num);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {
            difficulties.add(st.nextToken());
        }

        List<String> sorted = new ArrayList<>(difficulties);
        Collections.sort(sorted, new DifficultyComparator());

        List<String> wrongDifficulties = new ArrayList<>();
        for (int i = 0; i < num; i++) {
            if (sorted.get(i).equals(difficulties.get(i))) {
                continue;
            }
            wrongDifficulties.add(difficulties.get(i));
        }

        if (wrongDifficulties.isEmpty()) {
            bw.write("OK");
        } else {
            Collections.sort(wrongDifficulties, new DifficultyComparator());
            bw.write("KO");
            bw.newLine();
            bw.write(wrongDifficulties.get(0));
            bw.write(' ');
            bw.write(wrongDifficulties.get(1));
        }
        bw.newLine();
        bw.flush();

        br.close();
        bw.close();
    }
}
