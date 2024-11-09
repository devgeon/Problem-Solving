// BOJ-01806 / 부분합
// devgeon, 2024.11.09, C++17
// https://www.acmicpc.net/problem/1806

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INTMAX = (1U << 31) - 1;
    int size = 0, threshold = 0;
    int num = 0, sum = 0, answer = INTMAX;
    queue<int> consecutive_subsequence;

    cin >> size >> threshold;

    for (int i = 0; i < size; i++) {
        cin >> num;
        if (num >= threshold) {
            answer = 1;
            break;
        }
        consecutive_subsequence.push(num);
        sum += num;
        if (sum < threshold) {
            continue;
        }
        while (sum >= threshold) {
            sum -= consecutive_subsequence.front();
            consecutive_subsequence.pop();
        }
        if (answer > consecutive_subsequence.size() + 1) {
            answer = consecutive_subsequence.size() + 1;
        }
    }

    cout << (answer == INTMAX ? 0 : answer) << endl;

    return 0;
}
