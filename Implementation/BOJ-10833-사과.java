// BOJ-10833 / 사과
// devgeon, 2024.03.18, Java 11
// https://www.acmicpc.net/problem/10833

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException {
        int num_of_schools = 0, num_of_students = 0, num_of_apples = 0, answer = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        num_of_schools = Integer.parseInt(br.readLine());

        for (int i = 0; i < num_of_schools; i++) {
            st = new StringTokenizer(br.readLine());

            num_of_students = Integer.parseInt(st.nextToken());
            num_of_apples = Integer.parseInt(st.nextToken());

            answer += num_of_apples % num_of_students;
        }

        bw.write(String.valueOf(answer));
        bw.newLine();

        bw.flush();
        br.close();
        bw.close();
    }
}
