// BOJ-20363 / 당근 키우기
// devgeon, 2024.06.05, C++17
// https://www.acmicpc.net/problem/20363

#include <iostream>

using namespace std;

int main() {
    int light = 0, water = 0;
    cin >> light >> water;
    cout << light + water + min(light, water) / 10 << endl;
    return 0;
}
