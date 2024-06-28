// BOJ-26015 / Enjoyable Entree
// devgeon, 2024.06.28, C++17
// https://www.acmicpc.net/problem/26015

#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long day = 0;
    cin >> day;

    if (day >= 30) {
        cout << "33.333333 66.666667" << endl;
        return 0;
    }

    vector<double> pi(3, 0);
    vector<double> tau(3, 0);
    pi[0] = 1;
    tau[1] = 1;

    for (int i = 2; i < day; i++) {
        pi[i % 3] = 0.5 * (pi[(i + 2) % 3] + pi[(i + 1) % 3]);
        tau[i % 3] = 0.5 * (tau[(i + 2) % 3] + tau[(i + 1) % 3]);
    }

    cout << fixed;
    cout.precision(6);
    cout << pi[(day - 1) % 3] * 100 << ' ' << tau[(day - 1) % 3] * 100 << endl;

    return 0;
}
