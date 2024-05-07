// BOJ-02293 / 동전 1
// devgeon, 2024.05.07, C++17
// https://www.acmicpc.net/problem/2293

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, price = 0;
    cin >> num >> price;

    vector<int> coins(num, 0);
    for (int &n : coins) {
        cin >> n;
    }
    vector<int> cache(price, 0);

    for (int i = 0; i < num; i++) {
        cache[coins[i] - 1]++;
        for (int j = coins[i]; j < price; j++) {
            cache[j] += cache[j - coins[i]];
        }
    }

    cout << cache[price - 1] << endl;
    return 0;
}
