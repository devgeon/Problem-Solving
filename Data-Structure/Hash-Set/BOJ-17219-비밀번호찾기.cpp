// BOJ-17219 / 비밀번호 찾기
// devgeon, 2024.10.01, C++17
// https://www.acmicpc.net/problem/17219

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_passwords = 0, num_of_queries = 0;
    string site = "", password = "";
    cin >> num_of_passwords >> num_of_queries;

    unordered_map<string, string> vault;
    while (num_of_passwords--) {
        cin >> site >> password;
        vault[site] = password;
    }

    while (num_of_queries--) {
        cin >> site;
        cout << vault[site] << '\n';
    }

    return 0;
}
