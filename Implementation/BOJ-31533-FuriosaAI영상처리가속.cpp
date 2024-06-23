// BOJ-31533 / Furiosa AI 영상 처리 가속
// devgeon, 2024.06.23, C++17
// https://www.acmicpc.net/problem/31533

#include <iostream>

using namespace std;

int main() {
    int times = 0;
    double speed1 = 0, speed2 = 0, answer = 0;
    cin >> times >> speed1 >> speed2;

    answer = max(speed1, speed2);
    answer = min(speed1 / times + speed2, answer);
    answer = min(speed1 + speed2 / times, answer);
    answer = min(speed1 * 2 / times, answer);
    answer = min(speed2 * 2 / times, answer);

    cout << fixed;
    cout.precision(6);
    cout << answer << endl;

    return 0;
}
