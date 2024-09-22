// BOJ-10280 / Pizza voting
// devgeon, 2024.09.22, Java 11
// https://www.acmicpc.net/problem/10280

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

        int num = 0, fav = 0;
        int quotient = 0, remainder = 0;
        boolean success = true;

        num = Integer.parseInt(st.nextToken());
        fav = Integer.parseInt(st.nextToken());

        quotient = num / 3;
        remainder = num % 3;
        success = quotient < fav && fav <= quotient * 2 + (remainder + 1) / 2;

        bw.write(success ? "YES" : "NO");
        bw.newLine();

        br.close();
        bw.close();
    }

}
