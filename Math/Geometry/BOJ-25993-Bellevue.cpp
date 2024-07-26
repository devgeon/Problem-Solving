// BOJ-25993 / Bellevue
// devgeon, 2024.07.26, C++17
// https://www.acmicpc.net/problem/25993

#include <cmath>
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const double PI = 3.14159265358979323846;
    int num = 0, left_end = 0, right_end = 0;
    double tan = 0;
    cin >> num;

    map<int, int> points;
    for (int i = 0, position = 0, height = 0; i < num; i++) {
        cin >> position >> height;
        points.emplace(position, height);
    }
    left_end = points.begin()->first;
    right_end = points.rbegin()->first;

    for (auto it = points.begin()++; it != points.end()--; it++) {
        tan = max(tan, (double)it->second / (it->first - left_end));
        tan = max(tan, (double)it->second / (right_end - it->first));
    }

    cout << fixed;
    cout.precision(6);
    cout << atan(tan) * 180 / PI << endl;

    return 0;
}
