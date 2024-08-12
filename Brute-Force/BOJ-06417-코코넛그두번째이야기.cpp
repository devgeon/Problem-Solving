// BOJ-06417 / 코코넛 그 두 번째 이야기
// devgeon, 2024.08.12, C++17
// https://www.acmicpc.net/problem/6417

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, coconut = 0, headcount = 0;
    bool is_possible = true;

    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        for (headcount = num; headcount > 1; headcount--) {
            coconut = num;
            is_possible = true;
            for (int i = 0; i < headcount; i++) {
                coconut--;
                if (coconut % headcount != 0) {
                    is_possible = false;
                    break;
                }
                coconut /= headcount;
                coconut *= headcount - 1;
            }
            if (is_possible && coconut % headcount == 0) {
                break;
            }
        }
        cout << num << " coconuts, ";
        if (is_possible) {
            cout << headcount << " people and 1 monkey";
        } else {
            cout << "no solution";
        }
        cout << '\n';
    }

    return 0;
}
