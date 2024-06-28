// BOJ-01297 / TV 크기
// devgeon, 2024.06.28, C++17
// https://www.acmicpc.net/problem/1297

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int height = 0, weight = 0;
    int diagonal = 0, height_ratio = 0, width_ratio = 0;
    cin >> diagonal >> height_ratio >> width_ratio;

    height = sqrt((double)height_ratio * height_ratio * diagonal * diagonal /
                  (width_ratio * width_ratio + height_ratio * height_ratio));
    weight = sqrt((double)width_ratio * width_ratio * diagonal * diagonal /
                  (width_ratio * width_ratio + height_ratio * height_ratio));
    cout << height << ' ' << weight << endl;

    return 0;
}
