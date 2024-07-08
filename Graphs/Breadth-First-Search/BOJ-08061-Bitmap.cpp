// BOJ-08061 / Bitmap
// devgeon, 2024.07.08, C++17
// https://www.acmicpc.net/problem/8061

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Pos {
  public:
    int row = 0;
    int col = 0;

    Pos(int row = 0, int col = 0) {
        this->row = row;
        this->col = col;
    }

    bool is_over(int height, int width) {
        return (this->row < 0 || this->col < 0 || this->row >= height ||
                this->col >= width);
    };

    Pos operator+(const Pos &pos) const {
        return Pos(this->row + pos.row, this->col + pos.col);
    }
};

vector<Pos> diff = {Pos(1, 0), Pos(0, 1), Pos(-1, 0), Pos(0, -1)};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 181 * 2;
    int row = 0, col = 0;
    cin >> row >> col;

    Pos pos, temp;
    queue<Pos> queue;
    vector<vector<int>> image(row, vector<int>(col, 0));
    vector<vector<int>> answer(row, vector<int>(col, 0));
    for (int r = 0; r < row; r++) {
        cin.get();
        for (int c = 0; c < col; c++) {
            image[r][c] = cin.get() - '0';
            if (image[r][c] == 1) {
                queue.emplace(r, c);
            } else {
                answer[r][c] = MAX;
            }
        }
    }

    while (queue.size()) {
        pos = queue.front();
        queue.pop();
        for (const Pos &d : diff) {
            temp = pos + d;
            if (temp.is_over(row, col) ||
                answer[temp.row][temp.col] <= answer[pos.row][pos.col] + 1) {
                continue;
            }
            queue.push(temp);
            answer[temp.row][temp.col] = answer[pos.row][pos.col] + 1;
        }
    }

    for (const vector<int> &line : answer) {
        for (const int &pixel : line) {
            cout << pixel << ' ';
        }
        cout << '\n';
    }

    return 0;
}
