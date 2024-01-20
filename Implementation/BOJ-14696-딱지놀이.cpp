// BOJ-14696 / 딱지놀이
// devgeon, 2024.01.20, C++17
// https://www.acmicpc.net/problem/14696

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int TYPE = 4;
    char result = '\0';
    int round = 0, count = 0, input = 0;
    vector<int> ddakjis(TYPE * 2, 0);
    cin >> round;

    for (int r = 0; r < round; r++) {
        for (int i = 0; i < ddakjis.size(); i++) {
            ddakjis[i] = 0;
        }
        for (int p = 0; p <= 4; p += 4) {
            cin >> count;
            for (int i = 0; i < count; i++) {
                cin >> input;
                ddakjis[input - 1 + p]++;
            }
        }
        result = '\0';
        for (int t = TYPE - 1; t >= 0; t--) {
            if (ddakjis[t] > ddakjis[t + TYPE]) {
                result = 'A';
                break;
            } else if (ddakjis[t] < ddakjis[t + TYPE]) {
                result = 'B';
                break;
            }
        }
        if (result == '\0') {
            result = 'D';
        }
        cout << result << "\n";
    }

    return 0;
}
