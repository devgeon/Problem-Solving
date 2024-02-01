// BOJ-15003 / Amsterdam Distance
// devgeon, 2024.02.01, C++17
// https://www.acmicpc.net/problem/15003

#include <iostream>

using namespace std;

int main() {
    const double PI = 3.14159265358979;
    int m = 0, n = 0;
    float r = 0.0f;
    int ax = 0, ay = 0, bx = 0, by = 0;
    double answer = 2000.0, distance = 0.0;
    int x_diff = 0, y_diff = 0;
    cin >> m >> n >> r;
    cin >> ax >> ay >> bx >> by;

    x_diff = abs(ax - bx);
    y_diff = abs(ay - by);
    for (int route = min(ay, by); route >= 0; route--, y_diff += 2) {
        distance =
            ((PI * route * x_diff / m + static_cast<double>(y_diff)) * r / n);
        if (distance < answer) {
            answer = distance;
        } else {
            break;
        }
    }

    cout.precision(15);
    cout << answer << endl;

    return 0;
}
