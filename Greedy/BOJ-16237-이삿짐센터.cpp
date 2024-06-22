// BOJ-16237 / 이삿짐센터
// devgeon, 2024.06.22, C++17
// https://www.acmicpc.net/problem/16237

#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX_WEIGHT = 5;
    int baskets = 0, one = 0, two = 0, three = 0, four = 0, five = 0;
    cin >> one >> two >> three >> four >> five;

    baskets += five;
    baskets += four;
    one -= four;

    baskets += three;
    one -= three - two > 0 ? (three - two) * 2 : 0;
    two -= three;

    two = max(0, two);
    baskets += (two + 1) / 2;
    one -= two / 2;
    one -= two % 2 ? 3 : 0;

    one = max(0, one);
    baskets += (one + MAX_WEIGHT - 1) / MAX_WEIGHT;

    cout << baskets << endl;

    return 0;
}
