// BOJ-10867 / 중복 빼고 정렬하기
// devgeon, 2025.03.09, Java 11
// https://www.acmicpc.net/problem/10867

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());

        TreeSet<Integer> bst = new TreeSet<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {
            bst.add(Integer.parseInt(st.nextToken()));
        }

        for (int n : bst) {
            bw.write(Integer.toString(n));
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
