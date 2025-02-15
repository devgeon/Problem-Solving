// BOJ-32531 / 래환이의 수강신청 대작전
// devgeon, 2025.02.15, Java 11
// https://www.acmicpc.net/problem/32531

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int numOfSubjects = Integer.parseInt(st.nextToken());
        int numOfStudents = Integer.parseInt(st.nextToken());

        int[] registration = new int[numOfStudents];
        for (int i = 1; i < numOfSubjects; i++) {
            st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            for (int j = 0; j < count; j++) {
                int index = Integer.parseInt(st.nextToken()) - 1;
                registration[index] |= 1 << i;
            }
        }
        Arrays.sort(registration);

        int duplication = 0;
        for (int i = 1; i < numOfStudents; i++) {
            if (registration[i - 1] != registration[i]) {
                continue;
            }
            if (registration[i] == 0 || i > 1 && registration[i - 2] == registration[i]) {
                duplication = -1;
                break;
            }
            duplication++;
        }

        int exponent = numOfStudents - duplication - (registration[0] == 0 ? 1 : 0);
        int answer = (duplication < 0 ? 0 : 1 << exponent);
        System.out.println(answer);

        br.close();
    }
}
