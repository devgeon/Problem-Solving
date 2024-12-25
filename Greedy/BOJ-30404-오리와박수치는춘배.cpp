// BOJ-30404 / 오리와 박수치는 춘배
// devgeon, 2024.12.25, C++17
// https://www.acmicpc.net/problem/30404

#include <iostream>

#define INT_MIN 1 << 31

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, interval = 0;
    int count = 0, time = 0, last_clap = INT_MIN;

    cin >> num >> interval;
    for (int i = 0; i < num; i++) {
        cin >> time;
        if (last_clap + interval < time) {
            count++;
            last_clap = time;
        }
    }
    cout << count << endl;

    return 0;
}
