// BOJ-11080 / Almost an Anagram
// devgeon, 2025.01.25, Java 11
// https://www.acmicpc.net/problem/11080

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String word_a = st.nextToken();
        String word_b = st.nextToken();

        int[] counter = new int[26];
        for (char c : word_a.toCharArray()) {
            counter[c - 'a']++;
        }
        for (char c : word_b.toCharArray()) {
            counter[c - 'a']--;
        }

        int diffCount = 0;
        for (int i = 0; i < 26; i++) {
            if (counter[i] == 0) {
                continue;
            }
            if (Math.abs(counter[i]) > 1) {
                diffCount = Integer.MAX_VALUE;
                break;
            }
            diffCount++;
        }

        String message = "";
        if (word_a.equals(word_b)) {
            message = "identical to";
        } else if (diffCount == 0) {
            message = "an anagram of";
        } else if (diffCount <= 2) {
            message = "almost an anagram of";
        } else {
            message = "nothing like";
        }

        if (word_a.length() > word_b.length() ||
                word_a.length() == word_b.length() && word_a.compareTo(word_b) > 0) {
            String temp = word_a;
            word_a = word_b;
            word_b = temp;
        }

        bw.write(String.format("%s is %s %s\n", word_a, message, word_b));
        bw.flush();

        br.close();
        bw.close();
    }
}
