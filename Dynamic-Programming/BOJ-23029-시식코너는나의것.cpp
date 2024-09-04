// BOJ-23029 / 시식 코너는 나의 것
// devgeon, 2024.09.04, C++17
// https://www.acmicpc.net/problem/23029

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, food = 0, answer = 0;
    vector<vector<int>> cache(3, vector<int>(3, 0));
    cin >> num;

    cin >> food;
    cache[1][0] = food;
    for (int i = 1; i < num; i++) {
        cin >> food;
        cache[0][i % 3] = max({
            cache[0][(i + 2) % 3],
            cache[1][(i + 2) % 3],
            cache[2][(i + 2) % 3],
        });
        cache[1][i % 3] = cache[0][(i + 2) % 3] + food;
        cache[2][i % 3] = cache[1][(i + 2) % 3] + food / 2;
    }

    answer = max({
        cache[0][(num - 1) % 3],
        cache[1][(num - 1) % 3],
        cache[2][(num - 1) % 3],
    });
    cout << answer << endl;

    return 0;
}
