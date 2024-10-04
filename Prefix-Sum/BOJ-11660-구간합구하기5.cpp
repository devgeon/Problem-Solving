// BOJ-11660 / 구간 합 구하기 5
// devgeon, 2024.10.04, C++17
// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_elements = 0, num_queries = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, answer = 0;
    cin >> num_elements >> num_queries;

    vector<vector<int>> prefix_sum(num_elements + 1,
                                   vector<int>(num_elements + 1, 0));
    for (int r = 1; r <= num_elements; r++) {
        for (int c = 1; c <= num_elements; c++) {
            cin >> prefix_sum[r][c];
            prefix_sum[r][c] += prefix_sum[r - 1][c];
            prefix_sum[r][c] += prefix_sum[r][c - 1];
            prefix_sum[r][c] -= prefix_sum[r - 1][c - 1];
        }
    }

    while (num_queries--) {
        cin >> x1 >> y1 >> x2 >> y2;
        answer = prefix_sum[x2][y2];
        answer -= prefix_sum[x1 - 1][y2];
        answer -= prefix_sum[x2][y1 - 1];
        answer += prefix_sum[x1 - 1][y1 - 1];
        cout << answer << '\n';
    }

    return 0;
}
