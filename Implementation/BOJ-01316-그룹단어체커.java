// BOJ-01316 / 그룹 단어 체커
// devgeon, 2025.03.11, Java 11
// https://www.acmicpc.net/problem/1316

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    private static boolean check(String word) {
        boolean[] checked = new boolean[26];
        checked[word.charAt(0) - 'a'] = true;
        for (int i = 1, len = word.length(); i < len; i++) {
            int index = word.charAt(i) - 'a';
            if (word.charAt(i - 1) != word.charAt(i) && checked[index]) {
                return false;
            }
            checked[index] = true;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalWords = Integer.parseInt(br.readLine());
        int count = 0;

        for (int i = 0; i < totalWords; i++) {
            String word = br.readLine();
            if (check(word)) {
                count++;
            }
        }

        bw.write(Integer.toString(count));
        bw.flush();

        br.close();
        bw.close();
    }
}
