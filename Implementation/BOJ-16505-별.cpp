// BOJ-16505 / 별
// devgeon, 2024.12.17, C++17
// https://www.acmicpc.net/problem/16505

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    vector<string> star = {"*"};

    cin >> num;
    for (int i = 0; i < num; i++) {
        int size = star[0].size();
        for (int j = 0; j < size; j++) {
            star.push_back(star[j]);
        }
        for (int j = 0; j < size; j++) {
            star[j] += string(size - star[j].size(), ' ') + star[j];
        }
    }

    for (const string &line : star) {
        cout << line << '\n';
    }

    return 0;
}
