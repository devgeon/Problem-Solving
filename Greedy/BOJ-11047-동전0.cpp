// BOJ-11047 / 동전 0
// devgeon, 2024.05.11, C++17
// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, price = 0, count = 0;
    cin >> num >> price;

    vector<int> coins(num);
    for (auto it = coins.rbegin(); it != coins.rend(); it++) {
        cin >> *it;
    }

    for (int coin : coins) {
        count += price / coin;
        price %= coin;
    }

    cout << count << endl;
    return 0;
}
