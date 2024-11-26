// BOJ-30089 / 새로운 문자열 만들기
// devgeon, 2024.11.26, C++17
// https://www.acmicpc.net/problem/30089

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;

    string input = "", temp = "", output = "";

    while (cases--) {
        cin >> input;
        temp.clear();
        output.clear();

        auto it = input.end();
        for (char c : input) {
            temp.push_back(c);
            if (c != *(--it)) {
                output.append(temp);
                temp.clear();
                it = input.end();
            }
        }

        cout << input;
        for (auto it = output.rbegin(); it != output.rend(); it++) {
            cout << *it;
        }
        cout << '\n';
    }

    return 0;
}
