// BOJ-11588 / GEPPETTO
// devgeon, 2024.11.19, C++17
// https://www.acmicpc.net/problem/11588

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_TYPES = 20;
    int num_of_types = 0, num_of_restrs = 0;
    int answer = 0;
    vector<int> restrs;

    cin >> num_of_types >> num_of_restrs;
    restrs.reserve(num_of_restrs);
    for (int i = 0, a = 0, b = 0; i < num_of_restrs; i++) {
        cin >> a >> b;
        restrs.push_back(1 << (a - 1) | 1 << (b - 1));
    }

    for (int pizza = 0, end = 1 << num_of_types; pizza < end; pizza++) {
        bool possible = true;
        for (int mask : restrs) {
            if ((pizza & mask) == mask) {
                possible = false;
                break;
            }
        }
        answer += (int)possible;
    }
    cout << answer << endl;

    return 0;
}
