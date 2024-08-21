// BOJ-09530 / Football
// devgeon, 2024.08.21, C++17
// https://www.acmicpc.net/problem/9530

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, goal = 0, point = 0;
    vector<int> matches;
    cin >> num >> goal;

    for (int i = 0, scored = 0, received = 0; i < num; i++) {
        cin >> scored >> received;
        if (scored > received) {
            point += 3;
        } else {
            matches.push_back(received - scored);
        }
    }
    sort(matches.begin(), matches.end());

    for (int diff : matches) {
        if (diff > goal) {
            continue;
        }
        point += 1;
        goal -= diff;
        if (goal > 0) {
            point += 2;
            goal -= 1;
        }
    }
    cout << point << endl;

    return 0;
}
