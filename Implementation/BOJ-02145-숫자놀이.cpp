// BOJ-02145 / 숫자 놀이
// devgeon, 2024.04.23, C++17
// https://www.acmicpc.net/problem/2145

#include <iostream>

using namespace std;

int main() {
    int num = 0, answer = 0;

    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }

        do {
            answer = 0;
            do {
                answer += num % 10;
                num /= 10;
            } while (num > 0);
            num = answer;
        } while (answer > 9);

        cout << answer << '\n';
    }

    return 0;
}
