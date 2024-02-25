// BOJ-15651 / N과 M (3)
// devgeon, 2024.02.25, C++17
// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &sequence, const int range, const int length);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int range = 0, length = 0;
    vector<int> sequence;

    cin >> range >> length;

    solve(sequence, range, length);

    return 0;
}

void solve(vector<int> &sequence, const int range, const int length) {
    if (sequence.size() == length) {
        for (int i : sequence) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= range; i++) {
        sequence.push_back(i);
        solve(sequence, range, length);
        sequence.pop_back();
    }
}
