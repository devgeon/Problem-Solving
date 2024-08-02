// BOJ-25053 / Organizing SWERC
// devgeon, 2024.08.02, C++17
// https://www.acmicpc.net/problem/25053

#include <iostream>
#include <vector>

using namespace std;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}

void solve() {
    bool need_more_problems = false;
    int num = 0, beauty = 0, difficulty = 0, answer = 0;
    vector<int> problems(10, 0);

    cin >> num;
    while (num--) {
        cin >> beauty >> difficulty;
        problems[difficulty - 1] = max(beauty, problems[difficulty - 1]);
    }
    for (int b : problems) {
        if (b == 0) {
            need_more_problems = true;
            break;
        }
        answer += b;
    }
    if (need_more_problems) {
        cout << "MOREPROBLEMS" << '\n';
    } else {
        cout << answer << '\n';
    }
}
