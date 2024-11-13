// BOJ-19637 / IF문 좀 대신 써줘
// devgeon, 2024.11.13, C++17
// https://www.acmicpc.net/problem/19637

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_titles = 0, num_of_queries = 0;
    cin >> num_of_titles >> num_of_queries;

    int power = 0;
    string title = "";

    map<int, string> titles;
    for (int i = 0; i < num_of_titles; i++) {
        cin >> title >> power;
        if (titles.find(power) == titles.end()) {
            titles[power] = title;
        }
    }

    for (int i = 0; i < num_of_queries; i++) {
        cin >> power;
        cout << (titles.lower_bound(power)--)->second << '\n';
    }

    return 0;
}
