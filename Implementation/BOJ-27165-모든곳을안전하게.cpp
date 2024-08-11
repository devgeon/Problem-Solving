// BOJ-27165 / 모든 곳을 안전하게
// devgeon, 2024.08.11, C++17
// https://www.acmicpc.net/problem/27165

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, dice = 0, from = 0, to = 0;
    bool is_possible = false;
    vector<int> ones, board;

    cin >> num;
    board.reserve(num + 1);
    for (int i = 0, count = 0; i < num + 1; i++) {
        cin >> count;
        if (count == 1) {
            ones.push_back(i);
        }
        board.push_back(count);
    }
    cin >> dice;

    if (ones.size() >= 3) {
        is_possible = false;
    } else if (ones.size() == 2) {
        is_possible = (ones[1] - ones[0] == dice);
        from = ones[0], to = ones[1];
    } else if (ones.size() == 1) {
        if (ones[0] >= dice && board[ones[0] - dice] > 2) {
            is_possible = true;
            from = ones[0] - dice, to = ones[0];
        } else if (ones[0] <= num - dice && board[ones[0] + dice] > 0) {
            is_possible = true;
            from = ones[0], to = ones[0] + dice;
        }
    } else {
        for (int i = 0; i < num; i++) {
            if (board[i] > 2 && board[i + dice] > 1) {
                is_possible = true;
                from = i, to = i + dice;
                break;
            }
        }
    }
    if (is_possible) {
        cout << "YES" << '\n' << from << ' ' << to << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
