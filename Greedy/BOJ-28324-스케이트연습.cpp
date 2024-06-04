// BOJ-28324 / 스케이트 연습
// devgeon, 2024.06.04, C++17
// https://www.acmicpc.net/problem/28324

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, speed = 0;
    long long answer = 0;
    cin >> num;

    vector<int> limits(num);
    for (int &lim : limits) {
        cin >> lim;
    }

    for (auto it = limits.rbegin(); it != limits.rend(); it++) {
        speed = min(*it, speed + 1);
        answer += speed;
    }
    cout << answer << endl;

    return 0;
}
