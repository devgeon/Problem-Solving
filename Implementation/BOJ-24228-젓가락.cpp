// BOJ-24228 / 젓가락
// devgeon, 2024.12.27, C++17
// https://www.acmicpc.net/problem/24228

#include <iostream>

using namespace std;

int main() {
    long long types = 0, pairs = 0, answer = 0;
    cin >> types >> pairs;

    answer = types + pairs * 2 - 1;
    cout << answer << endl;

    return 0;
}
