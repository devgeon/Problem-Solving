// BOJ-23080 / 스키테일 암호
// devgeon, 2024.03.05, C++17
// https://www.acmicpc.net/problem/23080

#include <iostream>

using namespace std;

int main() {
    int key = 0;
    string text = "";

    cin >> key >> text;

    for (int i = 0; i < text.length(); i++) {
        if (i % key) {
            continue;
        }
        cout << text[i];
    }

    return 0;
}
