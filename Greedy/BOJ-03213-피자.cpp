// BOJ-03213 / 피자
// devgeon, 2024.06.11, C++17
// https://www.acmicpc.net/problem/3213

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input = "";
    int num = 0, condition = 0, answer = 0;
    int quarter = 0, half = 0, three_quarters = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> input;
        if (input == "1/2") {
            half++;
        } else if (input == "1/4") {
            quarter++;
        } else {
            three_quarters++;
        }
    }

    answer = three_quarters + (half + 1) / 2;
    condition = quarter - three_quarters - (half & 1 ? 2 : 0);
    if (condition > 0) {
        answer += (condition - 1) / 4 + 1;
    }
    cout << answer << endl;

    return 0;
}
