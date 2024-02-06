// BOJ-30242 / 🧩 N-Queen (Easy)
// devgeon, 2024.02.06, C++17
// https://www.acmicpc.net/problem/30242

#include <iostream>
#include <vector>

using namespace std;

// print the board when it finds a possible layout
bool place_queen(vector<int> board);
void print_board(vector<int> &board);

int main() {
    int n = 0;
    cin >> n;
    vector<int> board(n, 0);
    for (int &i : board) {
        cin >> i;
        i--;
    }

    if (!place_queen(board)) {
        cout << -1 << "\n";
    }

    return 0;
}

bool place_queen(vector<int> board) {
    int n = board.size();
    bool skip = false, result = true;
    for (int row = 0; row < n; row++) {
        if (board[row] != -1) {
            continue;
        }
        for (int col = n / 2; col < n + n / 2; col++) {
            skip = false;
            for (int r = 0; r < n; r++) {
                if (board[r] == col % n ||
                    board[r] != -1 && (board[r] == col % n + r - row ||
                                       board[r] == col % n - r + row)) {
                    skip = true;
                    break;
                }
            }
            if (skip) {
                continue;
            }
            board[row] = col % n;
            result = place_queen(board);
            if (result) {
                return true;
            }
        }
        if (board[row] == -1) {
            return false;
        }
    }
    print_board(board);
    return true;
}

void print_board(vector<int> &board) {
    for (int i : board) {
        cout << i + 1;
        if (i != board.back()) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
}
