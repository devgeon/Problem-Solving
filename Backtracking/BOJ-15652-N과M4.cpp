// BOJ-15652 / N과 M (4)
// devgeon, 2024.02.27, C++17
// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &sequence, const int range, const int length);

int main() {
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

    for (int i = (sequence.empty() ? 1 : sequence.back()); i <= range; i++) {
        sequence.push_back(i);
        solve(sequence, range, length);
        sequence.pop_back();
    }
}
