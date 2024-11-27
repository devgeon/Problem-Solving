// BOJ-10897 / Inherited disease
// devgeon, 2024.11.27, C++17
// https://www.acmicpc.net/problem/10897

#include <iostream>

using namespace std;

int main() {
    const int DIV = 1'000'000'007;

    int max_gen = 0, child_pos = 0;
    cin >> max_gen;

    long long num = 0, min = 0, max = 0, next_min = 0, next_max = 0;

    for (int gen = 1; gen <= max_gen; gen++) {
        cin >> child_pos;

        next_min = (max + 1) % DIV;
        next_max = (((max - min + 1 + DIV) % DIV * gen) % DIV + max) % DIV;

        num = ((num - min + DIV) % DIV * gen) % DIV;
        num = ((num + child_pos) % DIV + max) % DIV;
        cout << num << '\n';

        min = next_min, max = next_max;
    }

    return 0;
}
