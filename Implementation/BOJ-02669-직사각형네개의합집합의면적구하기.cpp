// BOJ-02669 / 직사각형 네개의 합집합의 면적 구하기
// devgeon, 2025.01.14, C++17
// https://www.acmicpc.net/problem/2669

#include <bitset>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_X = 100, MAX_Y = 100;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, area = 0;
    bitset<MAX_X * MAX_Y> included;

    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                if (included[y * MAX_X + x]) {
                    continue;
                }
                area++;
                included.set(y * MAX_X + x);
            }
        }
    }
    cout << area << endl;

    return 0;
}
