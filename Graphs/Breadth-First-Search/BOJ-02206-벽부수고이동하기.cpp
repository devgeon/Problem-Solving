// BOJ-02206 / 벽 부수고 이동하기
// devgeon, 2023.12.14, C++17
// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Record {
  public:
    int row = 0, col = 0, broke = 0;

    Record(int row, int col, int broke) {
        this->row = row;
        this->col = col;
        this->broke = broke;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0, count = 1;
    int q_size = 0, r = 0, c = 0, broke = 0;
    cin >> row >> col;
    queue<Record> queue;
    vector<vector<bool>> map(row, vector<bool>(col, true));
    vector<vector<int8_t>> visited(row, vector<int8_t>(col, 0));
    for (r = 0; r < row; r++) {
        // 이전행 개행문자 무시
        for (c = -1; c < col; c++) {
            if (cin.get() == '1') {
                map[r][c] = false;
            }
        }
    }

    queue.push(Record(0, 0, 0));
    visited[0][0] = true;
    while (!(queue.empty() || visited[row - 1][col - 1])) {
        q_size = queue.size();
        while (q_size > 0) {
            r = queue.front().row;
            c = queue.front().col;
            broke = queue.front().broke;
            queue.pop();
            if (r > 0) {
                if (!(visited[r - 1][c] & 1 << (broke + 1)) &&
                    !(!(map[r - 1][c]) && broke)) {
                    queue.push(Record(
                        r - 1, c, broke + static_cast<int>(!map[r - 1][c])));
                    visited[r - 1][c] |= 1 << (broke + 1);
                }
            }
            if (r < row - 1) {
                if (!(visited[r + 1][c] & 1 << (broke + 1)) &&
                    !(!(map[r + 1][c]) && broke)) {
                    queue.push(Record(
                        r + 1, c, broke + static_cast<int>(!map[r + 1][c])));
                    visited[r + 1][c] |= 1 << (broke + 1);
                }
            }
            if (c > 0) {
                if (!(visited[r][c - 1] & 1 << (broke + 1)) &&
                    !(!(map[r][c - 1]) && broke)) {
                    queue.push(Record(
                        r, c - 1, broke + static_cast<int>(!map[r][c - 1])));
                    visited[r][c - 1] |= 1 << (broke + 1);
                }
            }
            if (c < col - 1) {
                if (!(visited[r][c + 1] & 1 << (broke + 1)) &&
                    !(!(map[r][c + 1]) && broke)) {
                    queue.push(Record(
                        r, c + 1, broke + static_cast<int>(!map[r][c + 1])));
                    visited[r][c + 1] |= 1 << (broke + 1);
                }
            }
            q_size--;
        }
        count++;
    }

    if (visited[row - 1][col - 1]) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
