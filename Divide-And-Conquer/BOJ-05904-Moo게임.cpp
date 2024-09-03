// BOJ-05904 / Moo 게임
// devgeon, 2024.09.03, C++17
// https://www.acmicpc.net/problem/5904

#include <iostream>

using namespace std;

int extract(int len);
int _extract(int len);

int main() {
    int num = 0;
    cin >> num;

    cout << (extract(num) == 1 ? 'm' : 'o') << endl;

    return 0;
}

int extract(int len) {
    return abs(_extract(len));
}

int _extract(int len) {
    int phase = 0, trim_len = 0;
    bool new_pattern = false;

    while (trim_len * 2 + phase + 3 < len) {
        trim_len = trim_len * 2 + phase + 3;
        phase++;
    }
    if (trim_len + phase + 3 < len) {
        trim_len += phase + 3;
        new_pattern = true;
    }

    len -= trim_len;
    while (new_pattern && len > 3) {
        len = _extract(len);
        new_pattern = len < 0;
        len *= (new_pattern ? -1 : 1);
    }

    return len;
}
