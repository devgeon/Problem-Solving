// BOJ-11758 / CCW
// devgeon, 2024.10.28, C++17
// https://www.acmicpc.net/problem/11758

#include <iostream>

using namespace std;

int main() {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0, ccw = 0;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    dx1 = x2 - x1, dy1 = y2 - y1;
    dx2 = x3 - x2, dy2 = y3 - y2;

    ccw = dx1 * dy2 - dy1 * dx2;
    ccw = (ccw > 0 ? 1 : (ccw < 0 ? -1 : 0));
    cout << ccw << endl;

    return 0;
}
