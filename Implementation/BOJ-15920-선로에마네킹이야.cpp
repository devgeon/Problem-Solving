// BOJ-15920 / 선로에 마네킹이야!!
// devgeon, 2024.01.07, C++17
// https://www.acmicpc.net/problem/15920

#include <iostream>

using namespace std;

int main() {
    int len = 0, time = 0, result = 0;
    char input = '\0';
    int pulled[2] = {0};

    cin >> len;
    while (len && time < 2) {
        cin >> input;
        if (input == 'W') {
            time++;
        } else {
            pulled[time]++;
        }
        len--;
    }

    if (time < 2) {
        result = 0;
    } else if (pulled[1]) {
        result = 6;
    } else if (pulled[0] & 1) {
        result = 1;
    } else {
        result = 5;
    }
    cout << result << endl;

    return 0;
}
