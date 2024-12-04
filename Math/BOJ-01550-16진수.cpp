// BOJ-01550 / 16진수
// devgeon, 2024.12.04, C++17
// https://www.acmicpc.net/problem/1550

#include <iostream>

using namespace std;

int main() {
    int num = 0;
    string hex = "";
    cin >> hex;

    for (int i = hex.size() - 1, place_value = 1; i >= 0; i--) {
        num += (isdigit(hex[i]) ? hex[i] - '0' : 10 + hex[i] - 'A') * place_value;
        place_value <<= 4;
    }
    cout << num << endl;

    return 0;
}
