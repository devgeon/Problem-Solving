// BOJ-11723 / 집합
// devgeon, 2024.09.24, C++17
// https://www.acmicpc.net/problem/11723

#include <bitset>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, elem = 0;
    cin >> num;
    string cmd = "";
    bitset<21> bit(0);

    while (num--) {
        cin >> cmd;
        if (cmd == "all") {
            bit.set();
            continue;
        } else if (cmd == "empty") {
            bit.reset();
            continue;
        }

        cin >> elem;
        if (cmd == "add") {
            bit.set(elem);
        } else if (cmd == "remove") {
            bit.reset(elem);
        } else if (cmd == "toggle") {
            bit.flip(elem);
        } else if (cmd == "check") {
            cout << bit[elem] << '\n';
        } else {
            cout << "command not found\n";
        }
    }

    return 0;
}
