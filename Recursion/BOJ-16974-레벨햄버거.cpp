// BOJ-16974 / 레벨 햄버거
// devgeon, 2024.03.25, C++17
// https://www.acmicpc.net/problem/16974

#include <iostream>
#include <vector>

using namespace std;

long long solve(int num, long long height);

int main() {
    int num = 0;
    long long height = 0;

    cin >> num >> height;

    cout << solve(num, height - 1) << endl;

    return 0;
}

long long solve(int num, long long height) {
    long long layers = (1LL << (num + 2)) - 3, patties = (1LL << (num + 1)) - 1,
              prev_layers = (1LL << (num + 1)) - 3, prev_patties = (1LL << num) - 1;

    if (height < num) {
        return 0;
    }
    if (layers - num <= height) {
        return patties;
    }
    if (height == layers / 2) {
        return (num == 0 ? 1 : prev_patties + 1);
    }
    if (height < layers / 2) {
        return solve(num - 1, height - 1);
    }
    // layers / 2 < height
    return solve(num - 1, height - prev_layers - 2) + prev_patties + 1;
}
