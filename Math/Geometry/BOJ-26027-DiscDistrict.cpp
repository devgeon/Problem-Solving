// BOJ-26027 / Disc District
// devgeon, 2024.07.19, C++17
// https://www.acmicpc.net/problem/26027

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long radius = 0, min_x = 0, min_y = 0;
    long long len = 0, min_len = 2'000'000'000'000;
    cin >> radius;

    for (long long x = 1, y = radius; x <= y; x++) {
        while (x * x + (y - 1) * (y - 1) > radius * radius) {
            y--;
        }
        len = x * x + y * y;
        if (len < min_len) {
            min_len = len;
            min_x = x, min_y = y;
        }
    }
    cout << min_x << ' ' << min_y << endl;

    return 0;
}
