// BOJ-16165 / 걸그룹 마스터 준석이
// devgeon, 2024.11.18, Java 11
// https://www.acmicpc.net/problem/16165

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int numOfGroups = 0, numOfQuizzes = 0;
        numOfGroups = Integer.parseInt(st.nextToken());
        numOfQuizzes = Integer.parseInt(st.nextToken());

        HashMap<String, List<String>> teams = new HashMap<>();
        HashMap<String, String> members = new HashMap<>();

        for (int i = 0; i < numOfGroups; i++) {
            String teamName = br.readLine();
            int numOfMembers = Integer.parseInt(br.readLine());
            teams.put(teamName, new ArrayList<String>(numOfMembers));
            for (int j = 0; j < numOfMembers; j++) {
                String memberName = br.readLine();
                teams.get(teamName).add(memberName);
                members.put(memberName, teamName);
            }
            teams.get(teamName).sort(Comparator.naturalOrder());
        }

        for (int i = 0; i < numOfQuizzes; i++) {
            String name = br.readLine();
            if (br.readLine().equals("0")) {
                for (String n : teams.get(name)) {
                    bw.write(n);
                    bw.newLine();
                }
            } else {
                bw.write(members.get(name));
                bw.newLine();
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
