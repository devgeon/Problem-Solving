// BOJ-01463 / 1로 만들기
// devgeon, 2024.05.03, C++17
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 1'000'000;

    int num = 0;
    cin >> num;

    vector<int> cache(num, MAX);
    cache[0] = 0;

    for (int i = 2; i <= num; i++) {
        if (i % 3 == 0) {
            cache[i - 1] = min(cache[i - 1], cache[i / 3 - 1] + 1);
        }
        if (i % 2 == 0) {
            cache[i - 1] = min(cache[i - 1], cache[i / 2 - 1] + 1);
        }
        cache[i - 1] = min(cache[i - 1], cache[i - 2] + 1);
    }

    cout << cache[num - 1] << endl;
    return 0;
}
