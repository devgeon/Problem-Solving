// BOJ-02010 / 플러그
// devgeon, 2024.01.10, C++17
// https://www.acmicpc.net/problem/2010

#include <iostream>

using namespace std;

int main() {
    int total_power_strips = 0, total_outlets = 0, outlets = 0;
    cin >> total_power_strips;
    for (int i = 0; i < total_power_strips; i++) {
        cin >> outlets;
        total_outlets += outlets;
    }
    cout << total_outlets - total_power_strips + 1 << endl;
    return 0;
}
