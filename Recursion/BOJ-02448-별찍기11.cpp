// BOJ-02448 / 별 찍기 - 11
// devgeon, 2025.01.01, C++17
// https://www.acmicpc.net/problem/2448

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<string> &result, const int target, const int size = 3) {
    if (size == target) {
        return;
    }

    vector<string> base;
    base.swap(result);
    const string blank = string(size, ' ');

    for (int r = 0; r < size; r++) {
        result.push_back(blank + base[r] + blank);
    }
    for (int r = 0; r < size; r++) {
        result.push_back(base[r] + base[r]);
    }

    solve(result, target, size * 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    vector<string> answer = {"  *   ", " * *  ", "***** "};

    cin >> num;
    solve(answer, num);
    for (const string &line : answer) {
        cout << line << '\n';
    }

    return 0;
}
