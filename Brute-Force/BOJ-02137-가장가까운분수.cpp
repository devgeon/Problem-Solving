// BOJ-02137 / 가장 가까운 분수
// devgeon, 2024.02.04, C++17
// https://www.acmicpc.net/problem/2137

#include <iostream>

using namespace std;

int main() {
    int numerator = 0, denominator = 0;
    cin >> numerator >> denominator;
    double decimal_fraction = static_cast<double>(numerator) / denominator;
    double diff = 0.0, min_diff = 1.0;

    for (int d = 2; d <= 32767; d++) {
        for (int n = max(1, static_cast<int>(decimal_fraction * d) - 1),
                 m = min(d - 1, static_cast<int>(decimal_fraction * d) + 1);
             n <= m; n++) {
            diff = abs(decimal_fraction - static_cast<double>(n) / d);
            if (diff == 0.0) {
                continue;
            }
            if (diff < min_diff) {
                numerator = n;
                denominator = d;
                min_diff = diff;
            }
        }
    }

    cout << numerator << " " << denominator << endl;

    return 0;
}
