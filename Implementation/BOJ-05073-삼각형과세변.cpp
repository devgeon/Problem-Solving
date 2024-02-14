// BOJ-05073 / 삼각형과 세 변
// devgeon, 2024.02.14, C++17
// https://www.acmicpc.net/problem/5073

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> len(3, 0);

    while (true) {
        cin >> len[0] >> len[1] >> len[2];
        if (!(len[0] || len[1] || len[2])) {
            break;
        }

        if (len[0] == len[1] && len[1] == len[2]) {
            cout << "Equilateral\n";
            continue;
        }
        sort(len.begin(), len.end());
        if (len[2] >= len[0] + len[1]) {
            cout << "Invalid\n";
            continue;
        }
        if (len[0] == len[1] || len[1] == len[2]) {
            cout << "Isosceles\n";
            continue;
        }
        cout << "Scalene\n";
    }

    return 0;
}
