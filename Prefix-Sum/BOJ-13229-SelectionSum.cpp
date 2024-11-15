// BOJ-13229 / Selection Sum
// devgeon, 2024.11.15, C++17
// https://www.acmicpc.net/problem/13229

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 0, count = 0;
    cin >> len;

    vector<int> prefix_sum(len + 1, 0);
    for (int i = 1; i <= len; i++) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }

    cin >> count;
    for (int i = 0, start = 0, end = 0; i < count; i++) {
        cin >> start >> end;
        cout << prefix_sum[end + 1] - prefix_sum[start] << '\n';
    }

    return 0;
}
