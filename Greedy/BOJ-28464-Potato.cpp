// BOJ-28464 / Potato
// devgeon, 2024.06.07, C++17
// https://www.acmicpc.net/problem/28464

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, park = 0, sung = 0;
    cin >> num;

    vector<int> dishes(num, 0);
    for (int &d : dishes) {
        cin >> d;
    }
    sort(dishes.begin(), dishes.end(), greater());

    for (int i = 0; i < num / 2; i++) {
        park += dishes[i];
        sung += dishes[num - i - 1];
    }
    if (num & 1) {
        park += dishes[num / 2];
    }
    cout << sung << ' ' << park << endl;

    return 0;
}
