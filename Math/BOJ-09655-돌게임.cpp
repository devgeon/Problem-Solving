// BOJ-09655 / 돌 게임
// devgeon, 2024.11.24, C++17
// https://www.acmicpc.net/problem/9655

#include <iostream>

using namespace std;

int main() {
    int num = 0;
    cin >> num;

    cout << (num & 1 ? "SK" : "CY") << endl;

    return 0;
}
