// BOJ-26031 / Highest Hill
// devgeon, 2024.07.18, C++17
// https://www.acmicpc.net/problem/26031

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;
    long long answer = 0;
    long long local_max = 0, local_min1 = 0, local_min2 = 0;
    enum State { MIN1, MAX, MIN2, CALC };
    State state = MIN1;
    vector<long long> heights(num, 0);
    for (long long &n : heights) {
        cin >> n;
    }
    heights.push_back(318LL * 1'000'000'000 + 1);

    for (int i = 1; i <= num; i++) {
        if (state == MIN1 && heights[i] > heights[i - 1]) {
            local_min1 = heights[i - 1];
            state = MAX;
        } else if (state == MAX && heights[i] < heights[i - 1]) {
            local_max = heights[i - 1];
            state = MIN2;
        } else if (state == MIN2 && heights[i] > heights[i - 1]) {
            local_min2 = heights[i - 1];
            state = CALC;
        }
        if (state == CALC) {
            answer = max(answer, local_max - max(local_min1, local_min2));
            local_min1 = local_min2;
            state = MAX;
        }
    }
    cout << answer << endl;

    return 0;
}
