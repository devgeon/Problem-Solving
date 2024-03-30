// BOJ-01978 / 소수 찾기
// devgeon, 2024.03.30, C++17
// https://www.acmicpc.net/problem/1978

#include <iostream>

using namespace std;

bool isPrimeNumber(int num);

int main() {
    int num = 0, input = 0, count = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> input;
        if (isPrimeNumber(input)) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}

bool isPrimeNumber(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
