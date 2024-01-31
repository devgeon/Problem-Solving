// BOJ-13458 / 시험 감독
// devgeon, 2024.01.31, C++17
// https://www.acmicpc.net/problem/13458

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_rooms = 0, main_proctor = 0, sub_proctor = 0;
    long long answer = 0;
    cin >> total_rooms;
    answer = total_rooms;
    vector<int> examinees(total_rooms, 0);
    for (int &num : examinees) {
        cin >> num;
    }
    cin >> main_proctor >> sub_proctor;
    for (int num : examinees) {
        if (num > main_proctor) {
            answer += (num - main_proctor - 1) / sub_proctor + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
