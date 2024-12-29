// BOJ-02442 / 별 찍기 - 5
// devgeon, 2024.12.30, C++17
// https://www.acmicpc.net/problem/2442

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    for (int i = 1; i <= num; i++) {
        for (int j = num - i; j > 0; j--) {
            cout << ' ';
        }
        for (int j = i * 2 - 1; j > 0; j--) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
