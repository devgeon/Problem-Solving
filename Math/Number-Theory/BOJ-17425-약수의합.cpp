// BOJ-17425 / 약수의 합
// devgeon, 2024.03.26, C++17
// https://www.acmicpc.net/problem/17425

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1'000'000;
    int num_of_cases = 0, input = 0;
    vector<long long> cache(MAX, 1);

    cin >> num_of_cases;

    for (int i = 2; i <= MAX; i++) {
        for (int j = i; j <= MAX; j += i) {
            cache[j - 1] += i;
        }
    }
    for (int i = 1; i < MAX; i++) {
        cache[i] += cache[i - 1];
    }

    while (num_of_cases--) {
        cin >> input;
        cout << cache[input - 1] << "\n";
    }

    return 0;
}
