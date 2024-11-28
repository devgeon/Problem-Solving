// BOJ-11576 / Base Conversion
// devgeon, 2024.11.28, Java 11
// https://www.acmicpc.net/problem/11576

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static int pow(int num, int exp) {
        int result = 1;
        while (exp-- > 0) {
            result *= num;
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int num = 0;
        List<Integer> result = new ArrayList<>();

        int from = 0, to = 0, len = 0;
        from = Integer.parseInt(st.nextToken());
        to = Integer.parseInt(st.nextToken());
        len = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        for (int place_value = pow(from, len - 1), digit = 0; place_value > 0; place_value /= from) {
            digit = Integer.parseInt(st.nextToken());
            num += digit * place_value;
        }

        while (num > 0) {
            result.add(num % to);
            num /= to;
        }

        for (int i = result.size() - 1; i >= 0; i--) {
            bw.write(Integer.toString(result.get(i)));
            bw.write(' ');
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
