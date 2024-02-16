// BOJ-11399 / ATM
// devgeon, 2024.02.16, C++17
// https://www.acmicpc.net/problem/11399

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, answer = 0;
    cin >> num;
    vector<int> times(num, 0);
    for (int &t : times) {
        cin >> t;
    }
    sort(times.begin(), times.end());

    for (int i = 0; i < num; i++) {
        answer += times[i] * (num - i);
    }
    cout << answer << endl;

    return 0;
}
