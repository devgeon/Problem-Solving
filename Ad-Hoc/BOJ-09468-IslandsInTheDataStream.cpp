// BOJ-09468 / Islands in the Data Stream
// devgeon, 2024.07.15, C++17
// https://www.acmicpc.net/problem/9468

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, id = 0, count = 0;
    cin >> num;

    while (num--) {
        count = 0;
        cin >> id;
        for (int i = 0, cur = 0, prev = 0; i < 15; i++, prev = cur) {
            cin >> cur;
            if (cur > prev) {
                count++;
            }
        }
        cout << id << ' ' << count << '\n';
    }

    return 0;
}
