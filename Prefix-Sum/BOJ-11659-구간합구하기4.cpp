// BOJ-11659 / 구간 합 구하기 4
// devgeon, 2024.09.25, C++17
// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_elements = 0, num_queries = 0, begin = 0, end = 0;
    cin >> num_elements >> num_queries;

    vector<int> prefix_sum(num_elements + 1, 0);
    for (int i = 1; i <= num_elements; i++) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }

    while (num_queries--) {
        cin >> begin >> end;
        cout << prefix_sum[end] - prefix_sum[begin - 1] << '\n';
    }

    return 0;
}
