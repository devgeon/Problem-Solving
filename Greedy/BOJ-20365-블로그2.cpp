// BOJ-20365 / 블로그2
// devgeon, 2024.03.11, C++17
// https://www.acmicpc.net/problem/20365

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char last = 0, input = 0;
    int num = 0, count_red = 0, count_blue = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> input;
        if (input == last) {
            continue;
        }
        if (input == 'R') {
            count_red++;
        } else {
            count_blue++;
        }
        last = input;
    }

    cout << min(count_red, count_blue) + 1 << endl;

    return 0;
}
