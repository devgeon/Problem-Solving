// BOJ-07785 / 회사에 있는 사람
// devgeon, 2024.12.02, C++17
// https://www.acmicpc.net/problem/7785

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    string name = "", behavior = "";
    set<string, greater<>> list;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> name >> behavior;
        if (behavior == "enter") {
            list.insert(name);
        } else {
            list.erase(name);
        }
    }

    for (const string &name : list) {
        cout << name << '\n';
    }

    return 0;
}
