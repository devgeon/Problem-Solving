// BOJ-10164 / 격자상의 경로
// devgeon, 2023.12.18, C++17
// https://www.acmicpc.net/problem/10164

#include <iostream>

using namespace std;

long long cumulative_product(int start, int end);
int count_routes(int start_x, int start_y, int end_x, int end_y);

int main() {
    int row = 0, col = 0, result = 0;
    int point = 0, point_x = 0, point_y = 0;
    cin >> row >> col >> point;
    point_x = (point - 1) % col + 1;
    point_y = (point - 1) / col + 1;

    if (point) {
        result = (count_routes(1, 1, point_x, point_y) *
                  count_routes(point_x, point_y, col, row));
    } else {
        result = count_routes(1, 1, col, row);
    }

    cout << result << endl;
    return 0;
}

long long cumulative_product(int start, int end) {
    long long result = 1;
    while (start <= end) {
        result *= start;
        start++;
    }
    return result;
}

int count_routes(int start_x, int start_y, int end_x, int end_y) {
    int diff_x = 0, diff_y = 0;
    diff_x = end_x - start_x;
    diff_y = end_y - start_y;
    return cumulative_product(diff_x + 1, diff_x + diff_y) /
           cumulative_product(2, diff_y);
}
