// BOJ-15904 / UCPC는 무엇의 약자일까?
// devgeon, 2024.11.14, C++17
// https://www.acmicpc.net/problem/15904

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int i = 0;
    char ch = 0;
    bool is_possible = false;

    while (cin >> ch) {
        if (ch == "UCPC"[i]) {
            i++;
            if (i > 3) {
                is_possible = true;
                break;
            }
        }
    }
    cout << (is_possible ? "I love UCPC" : "I hate UCPC") << endl;

    return 0;
}
