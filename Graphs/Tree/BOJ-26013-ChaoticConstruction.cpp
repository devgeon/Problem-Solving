// BOJ-26013 / Chaotic Construction
// devgeon, 2024.06.27, C++17
// https://www.acmicpc.net/problem/26013

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char cmd = 0;
    bool possible = false;
    int seg_num = 0, seg_num2 = 0;
    int segments = 0, events = 0;
    set<int> closed;
    set<int>::iterator it_after, it_before;
    cin >> segments >> events;

    for (int i = 0; i < events; i++, cin.get()) {
        cin >> cmd >> seg_num;
        if (cmd == '-') {
            closed.insert(seg_num);
            continue;
        }
        if (cmd == '+') {
            closed.erase(seg_num);
            continue;
        }

        cin >> seg_num2;
        if (seg_num > seg_num2) {
            int temp = seg_num;
            seg_num = seg_num2;
            seg_num2 = temp;
        }
        possible = false;
        it_after = closed.lower_bound(seg_num);
        possible |= (it_after == closed.end() || *it_after > seg_num2);
        it_after = closed.lower_bound(seg_num2);
        it_before = closed.lower_bound(1);
        possible |= (it_after == closed.end() &&
                     (it_before == closed.end() || *it_before > seg_num));
        cout << (possible ? "possible" : "impossible") << '\n';
    }

    return 0;
}
