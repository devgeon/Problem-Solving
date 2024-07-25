// BOJ-25997 / Failing Flagship
// devgeon, 2024.07.25, C++17
// https://www.acmicpc.net/problem/25997

#include <iostream>
#include <map>

using namespace std;

double parse_direction(string direction);

int main() {
    string direction_string1 = "", direction_string2 = "";
    double direction1 = 0, direction2 = 0, answer = 0;

    cin >> direction_string1 >> direction_string2;
    direction1 = parse_direction(direction_string1);
    direction2 = parse_direction(direction_string2);
    answer = min(direction1, direction2) + 360 - max(direction1, direction2);
    answer = min(answer, abs(direction1 - direction2));

    cout << fixed;
    cout.precision(6);
    cout << answer << endl;

    return 0;
}

double parse_direction(string direction_string) {
    map<char, int> base = {
        {'N', 0}, {'N' + 1, 360}, {'E', 90}, {'S', 180}, {'W', 270}};
    double direction = 0, unit_angle = 45;

    direction = base[*(direction_string.rbegin())];
    for (auto it = direction_string.rbegin() + 1; it != direction_string.rend();
         it++) {
        if (base[(direction < 270 ? *it : *it + 1)] < direction) {
            direction -= unit_angle;
        } else {
            direction += unit_angle;
        }
        unit_angle /= 2;
    }
    return direction;
}
