// BOJ-33910 / 합의 최소
// devgeon, 2025.09.21, C++17
// https://www.acmicpc.net/problem/33910

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, min = 0;
    long long sum = 0;
    cin >> num;
    vector<int> seq(num, 0);
    for (int &a : seq) {
        cin >> a;
    }

    min = seq[num - 1];
    for (auto a = seq.rbegin(); a != seq.rend(); a++) {
        if (*a < min) {
            min = *a;
        }
        sum += min;
    }
    cout << sum << endl;

    return 0;
}
