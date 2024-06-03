// BOJ-09372 / 상근이의 여행
// devgeon, 2024.06.03, C++17
// https://www.acmicpc.net/problem/9372

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, input = 0;
    cin >> num;

    while (num--) {
        cin >> input;
        cout << input - 1 << '\n';
        cin >> input;
        for (int i = 0, garbage = 0; i < input; i++) {
            cin >> garbage >> garbage;
        }
    }

    return 0;
}
