// BOJ-17521 / Byte Coin
// devgeon, 2024.12.21, C++17
// https://www.acmicpc.net/problem/17521

#include <iostream>

using namespace std;

int main() {
    int duration = 0;
    long long money = 0, coin = 0;
    int curr_price = 0, next_price = 0;
    bool incresed = false;

    cin >> duration >> money;
    cin >> curr_price;

    for (int day = 1; day < duration; day++) {
        cin >> next_price;
        if (!incresed && curr_price < next_price) {
            coin += money / curr_price;
            money %= curr_price;
        } else if (incresed && curr_price > next_price) {
            money += coin * curr_price;
            coin = 0;
        }
        incresed = (curr_price == next_price ? incresed : curr_price < next_price);
        curr_price = next_price;
    }
    money += coin * curr_price;
    coin = 0;

    cout << money << endl;
    return 0;
}
