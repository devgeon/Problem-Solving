// BOJ-14940 / 쉬운 최단거리
// devgeon, 2024.02.08, C++17
// https://www.acmicpc.net/problem/14940

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Position {
  public:
    int row = 0;
    int col = 0;
    Position(int row = 0, int col = 0) {
        this->row = row;
        this->col = col;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0;
    cin >> row >> col;
    Position pos(0, 0);
    queue<Position> queue;
    vector<vector<int>> map(row, vector<int>(col, 0));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> map[r][c];
            if (map[r][c] == 2) {
                pos.row = r;
                pos.col = c;
                queue.push(pos);
                map[r][c] = 0;
            }
            map[r][c] *= -1;
        }
    }

    while (!queue.empty()) {
        pos = queue.front();
        queue.pop();
        if (pos.row > 0 && map[pos.row - 1][pos.col] == -1) {
            map[pos.row - 1][pos.col] = map[pos.row][pos.col] + 1;
            queue.push(Position(pos.row - 1, pos.col));
        }
        if (pos.col > 0 && map[pos.row][pos.col - 1] == -1) {
            map[pos.row][pos.col - 1] = map[pos.row][pos.col] + 1;
            queue.push(Position(pos.row, pos.col - 1));
        }
        if (pos.row < row - 1 && map[pos.row + 1][pos.col] == -1) {
            map[pos.row + 1][pos.col] = map[pos.row][pos.col] + 1;
            queue.push(Position(pos.row + 1, pos.col));
        }
        if (pos.col < col - 1 && map[pos.row][pos.col + 1] == -1) {
            map[pos.row][pos.col + 1] = map[pos.row][pos.col] + 1;
            queue.push(Position(pos.row, pos.col + 1));
        }
    }

    for (auto r : map) {
        for (auto c : r) {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}
