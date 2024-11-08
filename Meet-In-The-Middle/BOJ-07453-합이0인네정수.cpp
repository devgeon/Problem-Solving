// BOJ-07453 / 합이 0인 네 정수
// devgeon, 2024.11.08, C++17
// https://www.acmicpc.net/problem/7453

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 0;
    long long count = 0LL;
    cin >> len;

    vector<vector<int>> array(4, vector<int>(len, 0));
    array[0].reserve(len * len), array[1].reserve(len * len);
    for (int i = 0; i < len; i++) {
        cin >> array[0][i] >> array[1][i] >> array[2][i] >> array[3][i];
    }

    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len; j++) {
            array[0].push_back(array[0][i] + array[2][j]);
            array[1].push_back(array[1][i] + array[3][j]);
        }
        array[0][i] += array[2][0];
        array[1][i] += array[3][0];
    }
    array.pop_back();
    array.pop_back();

    sort(array.front().begin(), array.front().end());
    sort(array.back().begin(), array.back().end());

    for (int n : array.front()) {
        count += upper_bound(array.back().begin(), array.back().end(), -n) -
                 lower_bound(array.back().begin(), array.back().end(), -n);
    }
    cout << count << endl;

    return 0;
}
