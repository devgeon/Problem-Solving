// BOJ-10158 / 개미
// devgeon, 2024.05.18, C++17
// https://www.acmicpc.net/problem/10158

#include <iostream>

using namespace std;

int main() {
    int width = 0, height = 0, x = 0, y = 0, time = 0;
    cin >> width >> height >> x >> y >> time;

    x = (x + time) % (width * 2);
    if (x > width) {
        x = width * 2 - x;
    }
    y = (y + time) % (height * 2);
    if (y > height) {
        y = height * 2 - y;
    }
    cout << x << ' ' << y;

    return 0;
}
