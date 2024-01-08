// BOJ-02460 / 지능형 기차 2
// devgeon, 2024.01.08, C++17
// https://www.acmicpc.net/problem/2460

#include <iostream>

using namespace std;

int main() {
    const int TOTAL_STATIONS = 10;
    int get_on = 0, get_off = 0;
    int passengers = 0, max_passengers = 0;

    for (int station = 1; station <= TOTAL_STATIONS; station++) {
        cin >> get_off >> get_on;
        passengers -= get_off;
        passengers += get_on;
        if (passengers > max_passengers) {
            max_passengers = passengers;
        }
    }

    cout << max_passengers << endl;
    return 0;
}
