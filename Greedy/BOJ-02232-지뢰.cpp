// BOJ-02232 / 지뢰
// devgeon, 2024.05.17, C++17
// https://www.acmicpc.net/problem/2232

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<int> mines(num + 2, 0);
    for (int i = 1; i <= num; i++) {
        cin >> mines[i];
    }

    for (int i = 1; i <= num; i++) {
        if (mines[i] < mines[i - 1] || mines[i] < mines[i + 1]) {
            continue;
        }
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
