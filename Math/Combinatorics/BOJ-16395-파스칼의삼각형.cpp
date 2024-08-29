// BOJ-16395 / 파스칼의 삼각형
// devgeon, 2024.08.29, C++17
// https://www.acmicpc.net/problem/16395

#include <iostream>

using namespace std;

int combination(int n, int r);

int main() {
    int n = 0, r = 0;
    cin >> n >> r;
    cout << combination(n - 1, r - 1) << endl;
    return 0;
}

int combination(int n, int r) {
    int result = 1;
    for (int i = 1; i <= r; i++) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}
