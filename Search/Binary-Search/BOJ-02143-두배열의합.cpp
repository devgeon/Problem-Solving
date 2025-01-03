// BOJ-02143 / 두 배열의 합
// devgeon, 2025.01.03, C++17
// https://www.acmicpc.net/problem/2143

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int target = 0, len_a = 0, len_b = 0;
    long long answer = 0;
    cin >> target;

    cin >> len_a;
    vector<int> seq_a(len_a + 1);
    for (int i = 1, sum = 0; i <= len_a; i++) {
        cin >> seq_a[i];
        seq_a[i] += sum;
        sum = seq_a[i];
    }
    vector<int> sum_a;
    sum_a.reserve(len_a * (len_a + 1) / 2);
    for (int l = 1; l <= len_a; l++) {
        for (int s = 0, e = s + l; e <= len_a; s++, e++) {
            sum_a.push_back(seq_a[e] - seq_a[s]);
        }
    }
    sort(sum_a.begin(), sum_a.end());

    cin >> len_b;
    vector<int> seq_b(len_b + 1);
    for (int i = 1, sum = 0; i <= len_b; i++) {
        cin >> seq_b[i];
        seq_b[i] += sum;
        sum = seq_b[i];
    }
    vector<int> sum_b;
    sum_b.reserve(len_b * (len_b + 1) / 2);
    for (int l = 1; l <= len_b; l++) {
        for (int s = 0, e = s + l; e <= len_b; s++, e++) {
            sum_b.push_back(seq_b[e] - seq_b[s]);
        }
    }
    sort(sum_b.begin(), sum_b.end());

    for (const int n : sum_a) {
        answer += upper_bound(sum_b.begin(), sum_b.end(), target - n) -
                  lower_bound(sum_b.begin(), sum_b.end(), target - n);
    }
    cout << answer << endl;

    return 0;
}
