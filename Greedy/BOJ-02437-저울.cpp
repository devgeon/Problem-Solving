// BOJ-02437 / 저울
// devgeon, 2024.03.27, C++17
// https://www.acmicpc.net/problem/2437

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, range = 0;
    cin >> num;

    vector<int> weights(num, 0);
    for (int &w : weights) {
        cin >> w;
    }
    sort(weights.begin(), weights.end());

    if (weights[0] != 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= num; i++) {
        range += weights[i - 1];
        if (i == num || range < weights[i] - 1) {
            break;
        }
    }
    cout << range + 1 << endl;

    return 0;
}
