// BOJ-30678 / 별 안에 별 안에 별 찍기
// devgeon, 2025.01.05, C++17
// https://www.acmicpc.net/problem/30678

#include <iostream>
#include <vector>

using namespace std;

void star_in_star(vector<string> &star, const int num) {
    if (num == 0) {
        return;
    }

    const vector<string> base(star);
    const string blank(base.size(), ' ');
    star.clear();

    const vector<vector<bool>> pattern = {{0, 0, 1, 0, 0},
                                          {0, 0, 1, 0, 0},
                                          {1, 1, 1, 1, 1},
                                          {0, 1, 1, 1, 0},
                                          {0, 1, 0, 1, 0}};

    for (int row = 0; row < pattern.size(); row++) {
        for (int line = 0; line < base.size(); line++) {
            const vector<string> element = {blank, base[line]};
            star.push_back("");
            for (int col = 0; col < pattern[row].size(); col++) {
                star.back() += element[pattern[row][col]];
            }
        }
    }

    star_in_star(star, num - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<string> star = {"*"};
    star_in_star(star, num);

    for (const string &line : star) {
        cout << line << '\n';
    }

    return 0;
}
