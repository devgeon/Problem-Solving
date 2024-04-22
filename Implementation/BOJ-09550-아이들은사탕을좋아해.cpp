// BOJ-09550 / 아이들은 사탕을 좋아해
// devgeon, 2024.04.22, C++17
// https://www.acmicpc.net/problem/9550

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_cases = 0, total_types = 0;
    int candies = 0, needed = 0, answer = 0;

    cin >> total_cases;
    while (total_cases--) {
        cin >> total_types >> needed;
        answer = 0;
        while (total_types--) {
            cin >> candies;
            answer += candies / needed;
        }
        cout << answer << '\n';
    }

    return 0;
}
