// BOJ-15649 / N과 M (1)
// devgeon, 2024.02.24, C++17
// https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &sequence, vector<bool> &is_used, const int length);

int main() {
    int range = 0, length = 0;

    cin >> range >> length;

    vector<int> sequence;
    vector<bool> is_used(range, false);

    solve(sequence, is_used, length);

    return 0;
}

void solve(vector<int> &sequence, vector<bool> &is_used, const int length) {
    if (sequence.size() == length) {
        for (int i : sequence) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= is_used.size(); i++) {
        if (is_used[i - 1]) {
            continue;
        }

        sequence.push_back(i);
        is_used[i - 1] = true;

        solve(sequence, is_used, length);

        sequence.pop_back();
        is_used[i - 1] = false;
    }
}
