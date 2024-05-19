// BOJ-01002 / 터렛
// devgeon, 2024.05.19, C++17
// https://www.acmicpc.net/problem/1002

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0, answer = 0;
    int distance_square = 0, radius_sum_square = 0, radius_diff_square = 0;
    int x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
    cin >> cases;

    while (cases--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        distance_square = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        radius_sum_square = (r1 + r2) * (r1 + r2);
        radius_diff_square = (r1 - r2) * (r1 - r2);

        if (distance_square == 0) {
            if (r1 == r2) {
                answer = -1;
            } else {
                answer = 0;
            }
        } else if (distance_square > radius_sum_square ||
                   distance_square < radius_diff_square) {
            answer = 0;
        } else if (distance_square == radius_sum_square ||
                   distance_square == radius_diff_square) {
            answer = 1;
        } else {
            answer = 2;
        }
        cout << answer << '\n';
    }

    return 0;
}
