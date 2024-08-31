// BOJ-17212 / 달나라 토끼를 위한 구매대금 지불 도우미
// devgeon, 2024.08.31, C++17
// https://www.acmicpc.net/problem/17212

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 100'000;
    int price = 0;
    cin >> price;

    vector<int> units = {1, 2, 5, 7};
    vector<int> cache(price + 1, MAX);
    cache[0] = 0;

    for (int unit : units) {
        for (int i = unit; i <= price; i++) {
            cache[i] = min(cache[i], cache[i - unit] + 1);
        }
    }
    cout << cache[price] << endl;

    return 0;
}
