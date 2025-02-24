// BOJ-02694 / 합이 같은 구간
// devgeon, 2025.02.24, Java 11
// https://www.acmicpc.net/problem/2694

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    private static BufferedReader br;
    private static BufferedWriter bw;

    private static int solve() throws IOException {
        int sum = 0, max = Integer.MIN_VALUE;
        int length = Integer.parseInt(br.readLine());
        List<Integer> sequence = new ArrayList<>(length);
        for (int i = length; i > 0; i -= 10) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0, end = Math.min(10, i); j < end; j++) {
                int num = Integer.parseInt(st.nextToken());
                sequence.add(num);
                sum += num;
                max = Math.max(max, num);
            }
        }
        if (max > (sum >> 1)) {
            return sum;
        }

        List<Integer> primeFactors = findPrimeFactors(sum);
        TreeSet<Integer> divisors = findDivisors(primeFactors);
        for (int divisor : divisors) {
            if (divisor < max) {
                continue;
            }
            int group = 0;
            for (int num : sequence) {
                group += num;
                if (group > divisor) {
                    break;
                } else if (group == divisor) {
                    group = 0;
                }
            }
            if (group == 0) {
                return divisor;
            }
        }
        return sum;
    }

    private static List<Integer> findPrimeFactors(int num) {
        List<Integer> primeFactors = new ArrayList<>();
        while ((num & 1) == 0) {
            primeFactors.add(2);
            num >>= 1;
        }
        for (int i = 3; num > 1; i += 2) {
            while (num % i == 0) {
                primeFactors.add(i);
                num /= i;
            }
        }
        return primeFactors;
    }

    private static TreeSet<Integer> findDivisors(List<Integer> primeFactors) {
        TreeSet<Integer> divisors = new TreeSet<>();
        _findDivisors(primeFactors, divisors, 1, 0);
        return divisors;
    }

    private static void _findDivisors(List<Integer> primeFactors, TreeSet<Integer> divisors, int num, int index) {
        if (index == primeFactors.size()) {
            divisors.add(num);
            return;
        }
        int prime = primeFactors.get(index);
        _findDivisors(primeFactors, divisors, num, index + 1);
        _findDivisors(primeFactors, divisors, num * prime, index + 1);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int totalCases = Integer.parseInt(br.readLine());
        for (int i = 0; i < totalCases; i++) {
            bw.write(Integer.toString(solve()));
            bw.newLine();
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
