// BOJ-02851 / 슈퍼 마리오
// devgeon, 2024.01.14, C++17
// https://www.acmicpc.net/problem/2851

#include <iostream>

using namespace std;

int main() {
    int total_score = 0, score = 0;

    for (int i = 0; i < 10; i++) {
        cin >> score;
        if (total_score + score < 100) {
            total_score += score;
            continue;
        }
        if (100 - total_score >= total_score + score - 100) {
            total_score += score;
        }
        break;
    }

    cout << total_score << endl;
    return 0;
}
