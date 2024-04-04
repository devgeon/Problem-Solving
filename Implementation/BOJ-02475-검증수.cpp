// BOJ-02475 / 검증수
// devgeon, 2024.04.04, C++17
// https://www.acmicpc.net/problem/2475

#include <iostream>

using namespace std;

int main() {
    int input = 0, answer = 0;

    for (int i = 0; i < 5; i++) {
        cin >> input;
        answer += input * input;
    }
    cout << answer % 10 << endl;

    return 0;
}
