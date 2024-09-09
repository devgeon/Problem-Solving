// BOJ-01544 / 사이클 단어
// devgeon, 2024.04.29, Java 11
// https://www.acmicpc.net/problem/1544

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

class CycleWordList extends ArrayList<String> {
    boolean contains(String word) {
        for (int i = 0; i < this.size(); i++) {
            String w = this.get(i);
            if (w.length() != word.length()) {
                continue;
            }
            for (int start = 0; start < w.length(); start++) {
                boolean result = true;
                for (int check = 0; check < word.length(); check++) {
                    if (w.charAt((start + check) % w.length()) != word.charAt(check)) {
                        result = false;
                        break;
                    }
                }
                if (result) {
                    return true;
                }
            }
        }
        return false;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        String word = "";
        CycleWordList words = new CycleWordList();

        for (int i = 0; i < num; i++) {
            word = br.readLine();
            if (!words.contains(word)) {
                words.add(word);
            }
        }

        bw.write(String.valueOf(words.size()));
        bw.newLine();

        br.close();
        bw.close();
    }
}
