// BOJ-14566 / Dongjak N1
// devgeon, 2024.06.14, C++17
// https://www.acmicpc.net/problem/14566

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, min_dist = 0, count = 1;
    cin >> num;

    vector<int> coords(num, 0);
    for (int &c : coords) {
        cin >> c;
    }
    sort(coords.begin(), coords.end());

    min_dist = coords[1] - coords[0];
    for (int i = 2; i < num; i++) {
        if (coords[i] - coords[i - 1] < min_dist) {
            min_dist = coords[i] - coords[i - 1];
            count = 1;
        } else if (coords[i] - coords[i - 1] == min_dist) {
            count++;
        }
    }
    cout << min_dist << ' ' << count << endl;

    return 0;
}
