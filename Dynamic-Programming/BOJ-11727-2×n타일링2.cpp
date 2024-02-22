// BOJ-11727 / 2×n 타일링 2
// devgeon, 2024.02.22, C++17
// https://www.acmicpc.net/problem/11727

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int col = 0;
    vector<int> cases(3, 0);

    cin >> col;
    cases[0] = 1;
    cases[1] = 3;

    for (int i = 2; i < col; i++) {
        cases[i % 3] = (cases[(i - 1) % 3] + cases[(i - 2) % 3] * 2) % 10007;
    }

    cout << cases[(col - 1) % 3] << endl;

    return 0;
}
