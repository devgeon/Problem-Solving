// BOJ-30648 / 트릭 플라워
// devgeon, 2024.07.01, C++17
// https://www.acmicpc.net/problem/30648

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x = 0, y = 0, len = 0, answer = 0;
    cin >> x >> y >> len;

    vector<vector<bool>> garden(len, vector<bool>(len, false));

    do {
        garden[x][y] = true;
        answer++;
        if (x + y + 2 < len) {
            x++, y++;
        } else {
            x >>= 1, y >>= 1;
        }
    } while (garden[x][y] == false);
    cout << answer << endl;

    return 0;
}
