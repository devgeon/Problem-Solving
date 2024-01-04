// BOJ-02526 / 싸이클
// devgeon, 2024.01.04, C++17
// https://www.acmicpc.net/problem/2526

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int multiplier = 0, divisor = 0, value = 0, count = 1;
    vector<int> record(97, -1);

    cin >> multiplier >> divisor;
    multiplier %= divisor;
    value = multiplier;

    while (record[value] < 0) {
        record[value] = count;
        value *= multiplier;
        value %= divisor;
        count++;
    }

    cout << count - record[value] << endl;
    return 0;
}
