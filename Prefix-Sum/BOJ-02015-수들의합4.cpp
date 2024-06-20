// BOJ-02015 / 수들의 합 4
// devgeon, 2024.06.20, C++17
// https://www.acmicpc.net/problem/2015

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, target = 0;
    long long answer = 0;
    cin >> num >> target;

    vector<int> prefix_sum(num + 1, 0);
    unordered_map<int, int> counts;
    counts[0] = 1;

    for (int i = 1, input = 0; i <= num; i++) {
        cin >> input;
        prefix_sum[i] = prefix_sum[i - 1] + input;
        answer += counts[prefix_sum[i] - target];
        counts[prefix_sum[i]]++;
    }
    cout << answer << endl;

    return 0;
}
