// BOJ-05525 / IOIOI
// devgeon, 2024.09.30, C++17
// https://www.acmicpc.net/problem/5525

#include <iostream>

using namespace std;

inline int count_cases(int size, int num) {
    if (size > num) {
        return size - num;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, len = 0, count = 0, answer = 0;
    char prev = 'O', cur = 'O';
    cin >> num >> len;
    cin.get();

    for (int i = 0; i < len; prev = cur, i++) {
        cin >> cur;
        if (cur == 'O') {
            if (prev == 'O') {
                answer += count_cases(count, num);
                count = 0;
            }
        } else {
            if (prev == 'I') {
                answer += count_cases(count, num);
                count = 1;
            } else {
                count++;
            }
        }
    }
    answer += count_cases(count, num);
    cout << answer << endl;

    return 0;
}
