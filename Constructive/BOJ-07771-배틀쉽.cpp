// BOJ-07771 / 배틀쉽
// devgeon, 2024.07.16, C++17
// https://www.acmicpc.net/problem/7771

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int last_row = 0, last_col = 0;
    vector<string> prepared{"####.###.#", "###.##.##.",
                            "##.#.#....", ".........."};

    for (int i = 0, input = 0; i < 100; i++) {
        cin >> input;
        if (input == 100) {
            last_row = i / 10, last_col = i % 10;
        }
    }

    for (int row = 0, i = 0; row < 10; row++) {
        if (row == last_row) {
            prepared[3][last_col] = '#';
            cout << prepared[3] << '\n';
            prepared[3][last_col] = '.';
        } else if ((row - last_row) % 2 == 0) {
            cout << prepared[i++] << '\n';
        } else {
            cout << prepared[3] << '\n';
        }
    }

    return 0;
}
