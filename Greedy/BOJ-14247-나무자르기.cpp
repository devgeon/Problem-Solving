// BOJ-14247 / 나무 자르기
// devgeon, 2024.08.25, C++17
// https://www.acmicpc.net/problem/14247

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

    vector<int> growth(num, 0);
    for (int i = 0, height = 0; i < num; i++) {
        cin >> height;
        answer += height;
    }
    for (int &rate : growth) {
        cin >> rate;
    }
    sort(growth.begin(), growth.end());

    for (int i = 0; i < num; i++) {
        answer += growth[i] * i;
    }
    cout << answer << endl;

    return 0;
}
