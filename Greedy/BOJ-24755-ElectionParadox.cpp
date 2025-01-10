// BOJ-24755 / Election Paradox
// devgeon, 2025.01.10, C++17
// https://www.acmicpc.net/problem/24755

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, answer = 0;
    cin >> num;

    vector<int> populations(num, 0);
    for (int &n : populations) {
        cin >> n;
    }
    sort(populations.begin(), populations.end(), greater());

    for (int i = 0; i < (num >> 1); i++) {
        answer += populations[i];
    }
    for (int i = (num >> 1); i < num; i++) {
        answer += (populations[i] >> 1);
    }
    cout << answer << endl;

    return 0;
}
