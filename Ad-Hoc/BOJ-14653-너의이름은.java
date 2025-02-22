// BOJ-14653 / 너의 이름은
// devgeon, 2025.02.22, Java 11
// https://www.acmicpc.net/problem/14653

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    private static class Message {
        private int count;
        private int sender;

        public Message(int count, int sender) {
            this.count = count;
            this.sender = sender;
        }

        public static Message readMessage(BufferedReader br) throws IOException {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            int sender = st.nextToken().charAt(0) - 'A';
            return new Message(count, sender);
        }

        public int getCount() {
            return count;
        }

        public int getSender() {
            return sender;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int totalMembers = Integer.parseInt(st.nextToken());
        int totalMessages = Integer.parseInt(st.nextToken());
        int targetIndex = Integer.parseInt(st.nextToken());

        int prevCount = -1;
        int bitset = 1;

        for (int i = 1; i <= targetIndex; i++) {
            Message message = Message.readMessage(br);
            int count = message.getCount();
            int sender = message.getSender();
            if (count > prevCount) {
                prevCount = count;
                bitset = (count > 0 ? 1 : (1 << totalMembers) - 1);
            }
            bitset |= (1 << sender);
        }
        for (int i = targetIndex + 1; i <= totalMessages; i++) {
            Message message = Message.readMessage(br);
            int sender = message.getSender();
            bitset |= (1 << sender);
        }

        for (int i = 1; i < totalMembers; i++) {
            if ((bitset & 1 << i) == 0) {
                bw.write('A' + i);
                bw.write(' ');
            }
        }
        if (bitset == (1 << totalMembers) - 1) {
            bw.write("-1");
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
