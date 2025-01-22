// BOJ-17292 / 바둑이 포커
// devgeon, 2025.01.22, Java 11
// https://www.acmicpc.net/problem/17292

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;
import java.util.function.Function;

public class Main {
    private static int hexToInt(char c) {
        return c < 'a' ? c - '0' : c - 'a' + 10;
    }

    private static boolean isConsecutive(String pair) {
        int diff = Math.abs(hexToInt(pair.charAt(0)) - hexToInt(pair.charAt(2)));
        return diff == 1 || diff == 14;
    }

    private static boolean isSameNumber(String pair) {
        return pair.charAt(0) == pair.charAt(2);
    }

    private static boolean isSameColor(String pair) {
        return pair.charAt(1) == pair.charAt(3);
    }

    private static int getMaximumNumber(String pair) {
        return Math.max(hexToInt(pair.charAt(0)), hexToInt(pair.charAt(2)));
    }

    private static int getMinimumNumber(String pair) {
        return Math.min(hexToInt(pair.charAt(0)), hexToInt(pair.charAt(2)));
    }

    private static boolean isMaximumNumberBlack(String pair) {
        return hexToInt(pair.charAt(0)) >= hexToInt(pair.charAt(2)) && pair.charAt(1) == 'b'
                || hexToInt(pair.charAt(0)) <= hexToInt(pair.charAt(2)) && pair.charAt(3) == 'b';
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), ",");

        ArrayList<String> cards = new ArrayList<>();
        while (st.hasMoreTokens()) {
            cards.add(st.nextToken());
        }

        ArrayList<String> pairs = new ArrayList<>();
        for (int i = 0, size = cards.size(); i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                pairs.add(cards.get(i) + cards.get(j));
            }
        }

        pairs.sort(new Comparator<String>() {
            final int SWAP = 1, PASS = -1;

            public int compare(String a, String b) {
                List<Function<String, Boolean>> booleanFunctions = List.of(
                        Main::isConsecutive,
                        Main::isSameNumber,
                        Main::isSameColor);
                for (Function<String, Boolean> function : booleanFunctions) {
                    if (function.apply(a) && !function.apply(b)) {
                        return PASS;
                    } else if (!function.apply(a) && function.apply(b)) {
                        return SWAP;
                    }
                }

                List<Function<String, Integer>> numericFunctions = List.of(
                        Main::getMaximumNumber,
                        Main::getMinimumNumber);
                for (Function<String, Integer> function : numericFunctions) {
                    if (function.apply(a) > function.apply(b)) {
                        return PASS;
                    } else if (function.apply(a) < function.apply(b)) {
                        return SWAP;
                    }
                }

                if (isMaximumNumberBlack(a) && !isMaximumNumberBlack(b)) {
                    return PASS;
                } else if (!isMaximumNumberBlack(a) && isMaximumNumberBlack(b)) {
                    return SWAP;
                }
                return 0;
            }
        });

        for (String pair : pairs) {
            bw.write(pair);
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
