// BOJ-31564 / 육각타일미로 탈출기
// devgeon, 2024.10.12, C++17
// https://www.acmicpc.net/problem/31564

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Coord {
  public:
    int row = 0, col = 0;

    Coord(int row, int col) {
        this->row = row;
        this->col = col;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<int> DR = {0, 1, 1, 0, -1, -1};
    const vector<vector<int>> DC = {{1, 0, -1, -1, -1, 0}, {1, 1, 0, -1, 0, 1}};

    int row = 0, col = 0, obstacles = 0, distance = 0, answer = -1;
    cin >> row >> col >> obstacles;

    vector<vector<bool>> maze(row, vector<bool>(col, false));
    for (int i = 0, r = 0, c = 0; i < obstacles; i++) {
        cin >> r >> c;
        maze[r][c] = true;
    }

    queue<Coord> queue;
    maze[0][0] = true;
    queue.emplace(0, 0);
    queue.emplace(-1, -1);

    while (queue.size() > 1) {
        Coord coord = queue.front();
        queue.pop();
        if (coord.row < 0) {
            queue.push(coord);
            distance++;
            continue;
        }
        if (coord.row == row - 1 && coord.col == col - 1) {
            answer = distance;
            break;
        }

        for (int i = 0, r = 0, c = 0; i < 6; i++) {
            r = coord.row + DR[i];
            c = coord.col + DC[coord.row & 1][i];
            if (r < 0 || r >= row || c < 0 || c >= col || maze[r][c]) {
                continue;
            }
            maze[r][c] = true;
            queue.emplace(r, c);
        }
    }

    cout << answer << endl;

    return 0;
}
