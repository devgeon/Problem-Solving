// BOJ-23561 / Young한 에너지는 부족하다
// devgeon, 2024.06.17, C++17
// https://www.acmicpc.net/problem/23561

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, answer = 0;
    cin >> num;

    vector<int> energy(num * 3, 0);
    for (int &e : energy) {
        cin >> e;
    }
    sort(energy.begin(), energy.end());

    answer = energy[2 * num - 1] - energy[num];
    cout << answer << endl;

    return 0;
}
