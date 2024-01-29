// BOJ-16479 / 컵라면 측정하기
// devgeon, 2024.01.29, C++17
// https://www.acmicpc.net/problem/16479

#include <iostream>

using namespace std;

int main() {
    int hypotenuse = 0, big_diameter = 0, small_diameter = 0;
    cin >> hypotenuse >> big_diameter >> small_diameter;

    cout << hypotenuse * hypotenuse -
            static_cast<float>(big_diameter - small_diameter) / 2 *
            static_cast<float>(big_diameter - small_diameter) / 2
         << endl;

    return 0;
}
