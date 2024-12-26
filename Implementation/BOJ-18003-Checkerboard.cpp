// BOJ-18003 / Checkerboard
// devgeon, 2024.12.26, C++17
// https://www.acmicpc.net/problem/18003

#include <bitset>
#include <iostream>
#include <vector>

#define MAX_SIZE 50

using namespace std;

inline void print_line(const bitset<MAX_SIZE> &line, int size) {
    for (int i = 0; i < size; i++) {
        cout << (line[i] ? 'W' : 'B');
    }
    cout << '\n';
}

inline void get_first_line(bitset<MAX_SIZE> &line, vector<int> &widths) {
    int i = 0, cur = 0, prev = 0;
    for (int i = 0, end = widths.size(); i < end; i++) {
        cur += widths[i];
        if (i & 1) {
            line |= ((1LL << cur) - 1) - ((1LL << prev) - 1);
        }
        prev = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int row = 0, col = 0, v_cnt = 0, h_cnt = 0;
    cin >> row >> col >> v_cnt >> h_cnt;

    bitset<MAX_SIZE> line;
    vector<int> heights(v_cnt);
    vector<int> widths(h_cnt);

    for (int &h : heights) {
        cin >> h;
    }
    for (int &w : widths) {
        cin >> w;
    }
    get_first_line(line, widths);

    for (const int h : heights) {
        for (int i = 0; i < h; i++) {
            print_line(line, col);
        }
        line.flip();
    }

    return 0;
}
