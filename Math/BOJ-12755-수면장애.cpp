// BOJ-12755 / 수면 장애
// devgeon, 2024.04.17, C++17
// https://www.acmicpc.net/problem/12755

#include <iostream>

using namespace std;

int power10(int num);

int main() {
    int num = 0, len = 1, count = 9, answer = 0;
    cin >> num;

    while (len * count < num) {
        num -= len * count;
        len++;
        count *= 10;
    }
    num--;
    answer = num / len + power10(len);
    answer = answer % power10(len - num % len + 1) / power10(len - num % len);

    cout << answer << endl;
    return 0;
}

int power10(int num) {
    int result = 1;
    while (num > 1) {
        result *= 10;
        num--;
    }
    return result;
}
