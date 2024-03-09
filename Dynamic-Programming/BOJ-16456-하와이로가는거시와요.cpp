// BOJ-16456 / 하와와 대학생쨩 하와이로 가는 거시와요~
// devgeon, 2024.03.09, C++17
// https://www.acmicpc.net/problem/16456

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int DIVISOR = 1'000'000'009;
    int num = 0;
    cin >> num;

    vector<int> cache(4, 1);

    for (int i = 3; i < num; i++) {
        cache[i % 4] = (cache[(i + 1) % 4] + cache[(i + 3) % 4]) % DIVISOR;
    }

    if (num < 3) {
        cout << 1 << endl;
    } else {
        cout << (cache[(num - 1) % 4] + cache[(num - 3) % 4]) % DIVISOR << endl;
    }

    return 0;
}
