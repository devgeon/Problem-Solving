// BOJ-10994 / 별 찍기 - 19
// devgeon, 2024.12.31, C++17
// https://www.acmicpc.net/problem/10994

#include <deque>
#include <iostream>

using namespace std;

void solve(deque<string> &pattern, const int num) {
    if (num == 1) {
        return;
    }

    int len = pattern.front().size() + 4;
    string full_line = string(len, '*');
    string edge_line = "* " + string(len - 4, ' ') + " *";

    pattern.push_front(edge_line), pattern.push_front(full_line);
    pattern.push_back(edge_line), pattern.push_back(full_line);
    for (int i = 2, end = pattern.size() - 2; i < end; i++) {
        pattern[i] = "* " + pattern[i] + " *";
    }

    solve(pattern, num - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, size = 0;
    cin >> num;

    deque<string> pattern = {"*"};
    solve(pattern, num);

    for (const string &line : pattern) {
        cout << line << '\n';
    }

    return 0;
}
