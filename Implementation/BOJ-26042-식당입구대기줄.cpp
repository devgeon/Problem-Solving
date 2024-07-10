// BOJ-26042 / 식당 입구 대기 줄
// devgeon, 2024.07.10, C++17
// https://www.acmicpc.net/problem/26042

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, len = 0, max_len = 0, last_student = 0;
    cin >> num;

    for (int i = 0, type = 0, student = 0; i < num; i++) {
        cin >> type;
        if (type == 2) {
            len--;
            continue;
        }
        cin >> student;
        len++;
        if (len < max_len || (len == max_len && student > last_student)) {
            continue;
        }
        max_len = len;
        last_student = student;
    }
    cout << max_len << ' ' << last_student << endl;

    return 0;
}
