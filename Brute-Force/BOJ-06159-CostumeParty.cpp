// BOJ-06159 / Costume Party
// devgeon, 2024.04.19, C++17
// https://www.acmicpc.net/problem/6159

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, size = 0, answer = 0;
    cin >> num >> size;

    vector<int> cow(num, 0);
    for (int &n : cow) {
        cin >> n;
    }
    sort(cow.begin(), cow.end());

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (cow[i] + cow[j] > size) {
                break;
            }
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}
