// BOJ-03231 / 카드놀이
// devgeon, 2024.04.14, C++17
// https://www.acmicpc.net/problem/3231

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, input = 0, answer = 0;
    cin >> num;

    vector<bool> found(num, false);

    for (int i = 0; i < num; i++) {
        cin >> input;
        if (!found[input - 1]) {
            answer++;
        }
        found[input] = true;
    }

    cout << answer - 1 << endl;

    return 0;
}
