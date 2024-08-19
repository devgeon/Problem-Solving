// BOJ-01622 / 공통 순열
// devgeon, 2024.08.19, C++17
// https://www.acmicpc.net/problem/1622

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str_a = "", str_b = "";

    while (true) {
        getline(cin, str_a);
        getline(cin, str_b);
        if (cin.eof()) {
            break;
        }
        sort(str_a.begin(), str_a.end());
        sort(str_b.begin(), str_b.end());
        for (auto it_a = str_a.begin(), it_b = str_b.begin();
             it_a != str_a.end() && it_b != str_b.end();) {
            if (*it_a == *it_b) {
                cout << *it_a;
                it_a++, it_b++;
            } else {
                *it_a < *it_b ? it_a++ : it_b++;
            }
        }
        cout << '\n';
    }

    return 0;
}
