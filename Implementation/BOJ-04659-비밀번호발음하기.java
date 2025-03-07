// BOJ-04659 / 비밀번호 발음하기
// devgeon, 2025.03.07, Java 11
// https://www.acmicpc.net/problem/4659

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Pattern pattern = Pattern.compile("\\b[^aeiou\\s]+\\b|[aeiou]{3,}|[^aeiou\\s]{3,}|([^eo\\s])\\1");

        while (true) {
            String password = br.readLine();
            if (password.equals("end")) {
                break;
            }

            Matcher matcher = pattern.matcher(password);
            bw.write("<");
            bw.write(password);
            bw.write("> is ");
            bw.write(matcher.find() ? "not " : "");
            bw.write("acceptable.\n");
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
