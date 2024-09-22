// BOJ-01463 / 1로 만들기
// devgeon, 2024.09.22, C++17
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 1'000'000;

    int num = 0;
    cin >> num;

    vector<int> cache(num + 1, MAX);
    cache[1] = 0;

    for (int i = 1; i < num; i++) {
        if (i * 2 <= num) {
            cache[i * 2] = min(cache[i * 2], cache[i] + 1);
        }
        if (i * 3 <= num) {
            cache[i * 3] = min(cache[i * 3], cache[i] + 1);
        }
        cache[i + 1] = min(cache[i + 1], cache[i] + 1);
    }

    cout << cache[num] << endl;
    return 0;
}
