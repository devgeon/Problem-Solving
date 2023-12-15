// BOJ-01004 / 어린 왕자
// devgeon, 2023.12.15, C++17
// https://www.acmicpc.net/problem/1004

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int case_count = 0, system_count = 0, border_count = 0;
    int start_x = 0, start_y = 0, end_x = 0, end_y = 0;
    int system_x = 0, system_y = 0, system_radius = 0;
    bool included = false;
    cin >> case_count;

    while (case_count) {
        cin >> start_x >> start_y >> end_x >> end_y;
        cin >> system_count;
        border_count = 0;

        while (system_count) {
            cin >> system_x >> system_y >> system_radius;
            included = false;

            // 출발점을 포함하는 행성계
            if (((start_x - system_x) * (start_x - system_x) +
                 (start_y - system_y) * (start_y - system_y)) <
                (system_radius * system_radius)) {
                included = !included;
            }
            // 도착점을 포함하는 행성계
            if (((end_x - system_x) * (end_x - system_x) +
                 (end_y - system_y) * (end_y - system_y)) <
                (system_radius * system_radius)) {
                included = !included;
            }

            border_count += static_cast<int>(included);
            system_count--;
        }

        cout << border_count << endl;
        case_count--;
    }

    return 0;
}
