// BOJ-17204 / 죽음의 게임
// devgeon, 2024.06.08, C++17
// https://www.acmicpc.net/problem/17204

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, target = 0, answer = 0;
    cin >> num >> target;

    vector<int> point(num, 0);
    for (int &p : point) {
        cin >> p;
    }

    for (int curr = 0, next = 0; curr != target;) {
        if (point[curr] < 0) {
            answer = -1;
            break;
        }
        next = point[curr];
        point[curr] = -1;
        curr = next;
        answer++;
    }
    cout << answer << endl;

    return 0;
}
