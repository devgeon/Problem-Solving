// BOJ-02630 / 색종이 만들기
// devgeon, 2024.09.28, C++17
// https://www.acmicpc.net/problem/2630

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

const int BLUE = true, WHITE = false;
const int MAX_SIZE = 128;
using PaperRow = bitset<MAX_SIZE>;
using Paper = vector<PaperRow>;

class ReturnValue {
  public:
    int white = 0, blue = 0, sum = 0;

    ReturnValue() {}
    ReturnValue(int white, int blue, int sum) {
        this->white = white, this->blue = blue, this->sum = sum;
    }

    void operator+=(const ReturnValue &rv) {
        this->white += rv.white;
        this->blue += rv.blue;
        this->sum += rv.sum;
    }
};

ReturnValue solve(Paper &paper, int row, int col, int size) {
    int hf_size = (size >> 1);
    ReturnValue return_value;

    if (size > 1) {
        return_value += solve(paper, row, col, hf_size);
        return_value += solve(paper, row, col + hf_size, hf_size);
        return_value += solve(paper, row + hf_size, col, hf_size);
        return_value += solve(paper, row + hf_size, col + hf_size, hf_size);
    } else {
        return_value.sum = (paper[row][col] ? 1 : -1);
    }

    if (abs(return_value.sum) == size * size) {
        return_value.white = (int)(paper[row][col] == WHITE);
        return_value.blue = (int)(paper[row][col] == BLUE);
    }

    return return_value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size = 0;
    bool input = 0;
    cin >> size;

    ReturnValue return_value;
    Paper paper(size, PaperRow(0));
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cin >> input;
            paper[r][c] = input;
        }
    }

    return_value = solve(paper, 0, 0, size);

    cout << return_value.white << '\n';
    cout << return_value.blue << endl;

    return 0;
}
