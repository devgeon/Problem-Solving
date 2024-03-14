// BOJ-22973 / 점프 숨바꼭질
// devgeon, 2024.03.14, Java 11
// https://www.acmicpc.net/problem/22973

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        long destination = 0, jump_count = 0, position_range = 1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        destination = Long.parseLong(br.readLine());

        if (destination != 0 && destination % 2 == 0) {
            bw.write("-1");
        } else {
            while (!(-position_range < destination && destination < position_range)) {
                jump_count++;
                position_range <<= 1;
            }
            bw.write(String.valueOf(jump_count));
        }
        bw.newLine();

        bw.flush();
        br.close();
        bw.close();
    }
}
