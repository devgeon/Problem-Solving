// BOJ-02846 / 오르막길
// devgeon, 2023.11.30, C++17
// https://www.acmicpc.net/problem/2846

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int start = 0, previous = 1001, current = 0, height = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> current;
        if (current > previous) {
            if (start == 0) {
                start = previous;
            }
            height = max(height, current - start);
        } else {
            start = 0;
        }
        previous = current;
    }

    cout << height << endl;

    return 0;
}
