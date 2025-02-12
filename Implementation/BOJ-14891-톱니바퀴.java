// BOJ-14891 / 톱니바퀴
// devgeon, 2025.02.12, Java 11
// https://www.acmicpc.net/problem/14891

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final int NUM_OF_GEARS = 4;
    private static final int RIGHT_TOOTH = 2;
    private static final int LEFT_TOOTH = 6;
    private static final int NUM_OF_TEETH = RIGHT_TOOTH + LEFT_TOOTH;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] gears = new String[NUM_OF_GEARS];
        int[] topIndexes = new int[NUM_OF_GEARS];
        for (int i = 0; i < gears.length; i++) {
            gears[i] = br.readLine();
        }

        int totalQueries = Integer.parseInt(br.readLine());
        for (int i = 0; i < totalQueries; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken()) - 1;
            int direction = Integer.parseInt(st.nextToken());
            rotateGears(gears, topIndexes, index, direction);
        }

        int answer = 0;
        for (int i = 0; i < NUM_OF_GEARS; i++) {
            answer += (gears[i].charAt(topIndexes[i]) == '1' ? 1 << i : 0);
        }
        System.out.println(answer);

        br.close();
    }

    private static void rotateGears(String[] gears, int[] topIndexes, int index, int direction) {
        if (index < 0 || index >= NUM_OF_GEARS) {
            return;
        }
        _rotate(gears, topIndexes, index, direction, 0);
    }

    private static void _rotate(String[] gears, int[] topIndexes, int index, int rotateDirection,
            int movementDirection) {
        if (movementDirection >= 0 && checkConnection(gears, topIndexes, index, 1)) {
            _rotate(gears, topIndexes, index + 1, -rotateDirection, 1);
        }
        if (movementDirection <= 0 && checkConnection(gears, topIndexes, index, -1)) {
            _rotate(gears, topIndexes, index - 1, -rotateDirection, -1);
        }
        topIndexes[index] = (topIndexes[index] - rotateDirection + NUM_OF_TEETH) % NUM_OF_TEETH;
    }

    private static boolean checkConnection(String[] gears, int[] topIndexes, int index, int movementDirection) {
        int neighborIndex = index + movementDirection;
        if (neighborIndex < 0 || neighborIndex >= NUM_OF_GEARS) {
            return false;
        }
        int toothIndex = (topIndexes[index] + (movementDirection == 1 ? RIGHT_TOOTH : LEFT_TOOTH)) % NUM_OF_TEETH;
        int neighborToothIndex = (topIndexes[neighborIndex] + (movementDirection == 1 ? LEFT_TOOTH : RIGHT_TOOTH))
                % NUM_OF_TEETH;
        return (gears[index].charAt(toothIndex) != gears[neighborIndex].charAt(neighborToothIndex));
    }
}
