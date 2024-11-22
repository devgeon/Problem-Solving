// BOJ-31797 / 아~파트 아파트
// devgeon, 2024.11.22, C++17
// https://www.acmicpc.net/problem/31797

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int height = 0, people = 0, position = 0;
    cin >> height >> people;
    position = height % (people << 1);

    priority_queue<pair<int, int>> hands;
    for (int i = 0, h = 0; i < (people << 1); i++) {
        cin >> h;
        hands.emplace(h, i / 2);
        if (hands.size() > position) {
            hands.pop();
        }
    }
    cout << hands.top().second + 1 << endl;

    return 0;
}
