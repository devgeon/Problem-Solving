// BOJ-01758 / 알바생 강호
// devgeon, 2024.11.20, C++17
// https://www.acmicpc.net/problem/1758

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    long long answer = 0;
    cin >> num;

    vector<int> tips(num, 0);
    for (int &tip : tips) {
        cin >> tip;
    }
    sort(tips.begin(), tips.end(), greater());

    for (int i = 0; i < num; i++) {
        answer += max(0, tips[i] - i);
    }
    cout << answer << endl;

    return 0;
}
