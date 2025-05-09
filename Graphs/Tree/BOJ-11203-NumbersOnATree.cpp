// BOJ-11203 / Numbers On a Tree
// devgeon, 2025.05.03, C++17
// https://www.acmicpc.net/problem/11203

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int height = 0, index = 1;
    char direction = 0;

    cin >> height;
    while (cin >> direction) {
        index <<= 1;
        if (direction == 'R') {
            index++;
        }
    }
    index = (1 << height + 1) - index;

    cout << index << endl;
    return 0;
}
