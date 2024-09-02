// BOJ-11055 / 가장 큰 증가하는 부분 수열
// devgeon, 2024.09.02, C++17
// https://www.acmicpc.net/problem/11055

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size = 0, answer = 0;
    cin >> size;

    vector<int> seq(size + 1, 0);
    vector<int> sum(size + 1, 0);
    for (int i = 1; i <= size; i++) {
        cin >> seq[i];
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j]) {
                sum[i] = max(sum[i], sum[j] + seq[i]);
            }
        }
        answer = max(answer, sum[i]);
    }
    cout << answer << endl;

    return 0;
}
