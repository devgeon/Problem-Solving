// BOJ-01076 / 저항
// devgeon, 2024.12.07, C++17
// https://www.acmicpc.net/problem/1076

#include <iostream>

using namespace std;

int main() {
    long long value = 0;
    string color = "";
    string colors[] = {"brown", "red",    "orange", "yellow", "green",
                       "blue",  "violet", "grey",   "white"};

    for (int i = 0; i < 2; i++) {
        cin >> color;
        for (int j = 0, end = sizeof(colors) / sizeof(string); j < end; j++) {
            if (colors[j] == color) {
                value += (j + 1) * (i ? 1 : 10);
                break;
            }
        }
    }
    cin >> color;
    for (int i = 0, end = sizeof(colors) / sizeof(string); i < end; i++) {
        if (colors[i] != color) {
            continue;
        }
        for (int j = 0; j <= i; j++) {
            value *= 10;
        }
        break;
    }
    cout << value << endl;

    return 0;
}
