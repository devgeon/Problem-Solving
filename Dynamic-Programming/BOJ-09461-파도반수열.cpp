// BOJ-09461 / 파도반 수열
// devgeon, 2024.02.23, C++17
// https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, input = 0;
    vector<long long> sequence(100, 0);
    sequence[0] = sequence[1] = sequence[2] = 1;
    for (int i = 3; i < 100; i++) {
        sequence[i] = sequence[i - 2] + sequence[i - 3];
    }

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> input;
        cout << sequence[input - 1] << "\n";
    }

    return 0;
}
