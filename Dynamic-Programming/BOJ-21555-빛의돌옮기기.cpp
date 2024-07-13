// BOJ-21555 / 빛의 돌 옮기기
// devgeon, 2024.07.13, C++17
// https://www.acmicpc.net/problem/21555

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, cost = 0;
    long long prev_drag = 0, prev_carry = 0, cur_drag = 0, cur_carry = 0;
    cin >> num >> cost;

    vector<int> cost_to_drag(num, 0);
    for (int &n : cost_to_drag) {
        cin >> n;
    }
    vector<int> cost_to_carry(num, 0);
    for (int &n : cost_to_carry) {
        cin >> n;
    }

    for (int i = 0; i < num; i++) {
        cur_drag = min(prev_drag, prev_carry + cost) + cost_to_drag[i];
        cur_carry = min(prev_carry, prev_drag + cost) + cost_to_carry[i];
        prev_drag = cur_drag, prev_carry = cur_carry;
    }
    cout << min(cur_drag, cur_carry) << endl;

    return 0;
}
