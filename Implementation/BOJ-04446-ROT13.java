// BOJ-04446 / ROT13
// devgeon, 2024.09.19, Java 11
// https://www.acmicpc.net/problem/4446

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static void main(String[] args) throws IOException {

        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        final String VOWELS = "UOEYIAUOE", CONSONANTS = "FMLRSTQJVPGWCDHNZXKBFMLRSTQJVP";

        String input = "";
        char ch = '0';
        boolean isUpper = false, isVowel = false;

        while ((input = br.readLine()) != null) {
            for (int i = 0, idx = 0; i < input.length(); i++) {
                ch = input.charAt(i);
                if (!Character.isAlphabetic(ch)) {
                    bw.write(ch);
                    continue;
                }

                isUpper = Character.isUpperCase(ch);
                ch = Character.toUpperCase(ch);

                idx = VOWELS.indexOf(ch);
                isVowel = true;
                if (idx < 0) {
                    idx = CONSONANTS.indexOf(ch);
                    isVowel = false;
                }

                ch = isVowel ? VOWELS.charAt(idx + 3) : CONSONANTS.charAt(idx + 10);
                ch = isUpper ? ch : Character.toLowerCase(ch);

                bw.write(ch);
            }
            bw.write('\n');
        }
        bw.flush();

        br.close();
        bw.close();
    }

}
