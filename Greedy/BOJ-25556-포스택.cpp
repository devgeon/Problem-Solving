// BOJ-25556 / 포스택
// devgeon, 2023.12.06, C++17
// https://www.acmicpc.net/problem/25556

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    bool clean = true;
    vector<int> top(4, 0);
    vector<int> seq(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < n && clean; i++) {
        for (int t = 0; t < 4; t++) {
            if (top[t] < seq[i]) {
                top[t] = seq[i];
                break;
            }
            if (t == 3) {
                clean = false;
            }
        }
    }

    if (clean) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
