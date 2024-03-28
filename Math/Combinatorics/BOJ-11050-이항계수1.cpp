// BOJ-11050 / 이항 계수 1
// devgeon, 2024.03.28, C++17
// https://www.acmicpc.net/problem/11050

#include <iostream>

using namespace std;

int main() {
    int n = 0, k = 0, answer = 1;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        answer = answer * (n - i) / (i + 1);
    }

    cout << answer << endl;
    return 0;
}
