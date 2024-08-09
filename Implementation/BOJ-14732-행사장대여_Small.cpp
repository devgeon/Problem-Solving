// BOJ-14732 / 행사장 대여 (Small)
// devgeon, 2024.08.09, C++17
// https://www.acmicpc.net/problem/14732

#include <iostream>
#include <vector>

using namespace std;
using Bool = char;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, area = 0;
    int left = 0, bottom = 0, right = 0, top = 0;
    vector<vector<Bool>> sites(500, vector<Bool>(500, false));

    cin >> num;
    while (num--) {
        cin >> left >> bottom >> right >> top;
        for (int r = bottom; r < top; r++) {
            for (int c = left; c < right; c++) {
                if (sites[r][c] == true) {
                    continue;
                }
                sites[r][c] = true;
                area++;
            }
        }
    }
    cout << area << endl;

    return 0;
}
