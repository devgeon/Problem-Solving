// BOJ-26007 / Codepowers
// devgeon, 2024.08.07, C++17
// https://www.acmicpc.net/problem/26007

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_rounds = 0, num_queries = 0, threshold = 0, rating = 0;
    cin >> num_rounds >> num_queries >> threshold >> rating;

    vector<int> prefix_sum(num_rounds + 1, 0);
    prefix_sum[0] = (int)(rating < threshold);
    for (int i = 1, diff = 0; i < num_rounds + 1; i++) {
        cin >> diff;
        rating += diff;
        prefix_sum[i] = prefix_sum[i - 1] + (int)(rating < threshold);
    }

    for (int i = 0, begin = 0, end = 0, count = 0; i < num_queries; i++) {
        cin >> begin >> end;
        count = prefix_sum[end - 1] - prefix_sum[begin - 1];
        cout << count << '\n';
    }

    return 0;
}
