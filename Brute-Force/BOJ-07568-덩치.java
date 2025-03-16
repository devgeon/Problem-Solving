// BOJ-07568 / 덩치
// devgeon, 2025.03.16, Java 11
// https://www.acmicpc.net/problem/7568

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static class Person {
        private int weight;
        private int height;

        public Person(int weight, int height) {
            this.weight = weight;
            this.height = height;
        }

        public int getWeight() {
            return weight;
        }

        public int getHeight() {
            return height;
        }
    }

    private static int calcRank(List<Person> people, Person base) {
        int rank = 1;
        for (Person person : people) {
            if (person.getWeight() > base.getWeight() && person.getHeight() > base.getHeight()) {
                rank++;
            }
        }
        return rank;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());

        List<Person> people = new ArrayList<>(num);
        for (int i = 0; i < num; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int height = Integer.parseInt(st.nextToken());
            people.add(new Person(weight, height));
        }

        for (Person person : people) {
            int rank = calcRank(people, person);
            bw.write(Integer.toString(rank));
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
