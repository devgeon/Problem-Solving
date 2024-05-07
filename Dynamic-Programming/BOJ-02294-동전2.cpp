// BOJ-02294 / 동전 2
// devgeon, 2024.05.07, C++17
// https://www.acmicpc.net/problem/2294

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 10'001;
    int num = 0, price = 0;
    cin >> num >> price;

    vector<int> coins(num, 0);
    for (int &n : coins) {
        cin >> n;
    }
    vector<int> cache(price, MAX);

    for (int i = 0; i < num; i++) {
        cache[coins[i] - 1] = 1;
        for (int j = coins[i]; j < price; j++) {
            if (cache[j - coins[i]] == 0) {
                continue;
            }
            cache[j] = min(cache[j], cache[j - coins[i]] + 1);
        }
    }

    cout << (cache[price - 1] != MAX ? cache[price - 1] : -1) << endl;
    return 0;
}
