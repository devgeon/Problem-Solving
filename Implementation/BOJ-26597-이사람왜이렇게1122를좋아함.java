// BOJ-26597 / 이 사람 왜 이렇게 1122를 좋아함?
// devgeon, 2024.09.13, Java 11
// https://www.acmicpc.net/problem/26597

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

        int num = 0, count = 0;
        long input = 0L, upper = 0L, lower = 0L;
        char direction = ' ';

        num = Integer.parseInt(br.readLine());
        upper = 1_000_000_000_000_000_001L;
        lower = -1_000_000_000_000_000_001L;

        for (int i = 0; i < num; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            input = Long.parseLong(st.nextToken());
            direction = st.nextToken().charAt(0);

            if (direction == '^') {
                lower = Math.max(lower, input);
            } else {
                upper = Math.min(upper, input);
            }

            if (count == 0 && lower + 2 == upper) {
                count = i + 1;
            } else if (lower + 1 >= upper) {
                count = i + 1;
                break;
            }
        }

        if (lower + 1 >= upper) {
            bw.write("Paradox!\n");
            bw.write(String.valueOf(count));
        } else if (lower + 2 == upper) {
            bw.write("I got it!\n");
            bw.write(String.valueOf(count));
        } else {
            bw.write("Hmm...");
        }
        bw.newLine();

        br.close();
        bw.close();
    }

}
