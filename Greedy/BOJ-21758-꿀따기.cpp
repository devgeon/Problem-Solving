// BOJ-21758 / 꿀 따기
// devgeon, 2024.02.12, C++17
// https://www.acmicpc.net/problem/21758

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename Iterator> int check_loss(Iterator begin, Iterator end);

int main() {
    int num = 0, sum = 0, max_value = 0;
    cin >> num;
    vector<int> map(num, 0);
    for (int i = 0; i < num; i++) {
        cin >> map[i];
        sum += map[i];
        if (0 < i && i < num - 1) {
            max_value = max(map[i], max_value);
        }
    }

    cout << max({
                // forward
                ((sum - map.front()) * 2 - check_loss(map.begin(), map.end())),
                // backward
                ((sum - map.back()) * 2 - check_loss(map.rbegin(), map.rend())),
                // bidirectional
                (sum - map.front() - map.back() + max_value),
            })
         << endl;

    return 0;
}

template <typename Iterator> int check_loss(Iterator begin, Iterator end) {
    int sum = *(begin + 1) * 2, min_value = sum;
    for (auto it = begin + 2; it < end - 1; it++) {
        sum += *it * 2 - *(it - 1);
        min_value = min(sum, min_value);
    }
    return min_value;
}
