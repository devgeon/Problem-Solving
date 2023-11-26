// BOJ-24508 / 나도리팡
// devgeon, 2023.11.26, C++17
// https://www.acmicpc.net/problem/24508

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0, k = 0, t = 0, temp = 0;
    cin >> n >> k >> t;
    long long total = 0;
    int head = 0, tail = n - 1;
    vector<int> basket(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> basket[i];
        total += basket[i];
    }

    if (total == 0) {
        cout << "YES";
        return 0;
    }
    if (total % k != 0) {
        cout << "NO";
        return 0;
    }
    sort(basket.begin(), basket.end(), greater<int>());

    while (t > 0 && head < tail) {
        if (basket[head] < k) {
            if (basket[tail] > 0) {
                temp = min({k - basket[head], basket[tail], t});
                basket[head] += temp;
                basket[tail] -= temp;
                t -= temp;
            } else {
                tail--;
            }
        } else {
            head++;
        }
    }

    if (tail <= head ||
        (tail - head == 1 && basket[head] == k && basket[tail] == 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
