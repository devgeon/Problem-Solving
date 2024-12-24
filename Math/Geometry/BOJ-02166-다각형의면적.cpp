// BOJ-02166 / 다각형의 면적
// devgeon, 2024.12.24, C++17
// https://www.acmicpc.net/problem/2166

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    long long sum1 = 0, sum2 = 0;
    cin >> num;

    vector<vector<int>> points;
    points.reserve(num + 1);
    for (int i = 0; i < num; i++) {
        int x = 0, y = 0;
        cin >> x >> y;
        points.push_back(vector<int>{x, y});
    }
    points[num] = points[0];

    for (int i = 0; i < num; i++) {
        sum1 += (long long)points[i][0] * points[i + 1][1];
        sum2 += (long long)points[i + 1][0] * points[i][1];
    }
    cout << fixed << setprecision(1);
    cout << abs((sum1 - sum2) / 2.0) << endl;

    return 0;
}
