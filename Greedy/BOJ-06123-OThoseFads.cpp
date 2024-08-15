// BOJ-06123 / O Those Fads
// devgeon, 2024.08.15, C++17
// https://www.acmicpc.net/problem/6123

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, attract = 0, gain = 0, answer = 0;
    cin >> num >> attract >> gain;

    vector<int> resistances(num, 0);
    for (int &r : resistances) {
        cin >> r;
    }
    sort(resistances.begin(), resistances.end());

    for (int r : resistances) {
        if (r > attract) {
            break;
        }
        answer++;
        attract += gain;
    }
    cout << answer << endl;

    return 0;
}
