// BOJ-01796 / 신기한 키보드
// devgeon, 2024.01.24, C++17
// https://www.acmicpc.net/problem/1796

#include <iostream>

using namespace std;

const int LEFT = 0, RIGHT = 1;

int main() {
    string input = "";
    cin >> input;
    int left_index = 0, right_index = 0;
    int left_count = 0, right_count = 0, char_count = 0;
    int sides[2] = {-1, -1};
    int key_counts[2] = {0, 0};

    for (char c = 'a'; c <= 'z'; c++) {
        sides[0] = -1;
        sides[1] = -1;
        char_count = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == c) {
                if (sides[LEFT] == -1) {
                    sides[LEFT] = i;
                }
                sides[RIGHT] = i;
                char_count++;
            }
        }
        if (char_count == 0) {
            continue;
        }
        for (int direction : {LEFT, RIGHT}) {
            key_counts[direction] =
                min(abs(left_index - sides[direction]) + left_count,
                    abs(right_index - sides[direction]) + right_count) +
                sides[RIGHT] - sides[LEFT] + char_count;
        }
        left_index = sides[LEFT];
        right_index = sides[RIGHT];
        left_count = key_counts[RIGHT];
        right_count = key_counts[LEFT];
    }

    cout << min(left_count, right_count) << endl;
    return 0;
}
