// BOJ-01620 / 나는야 포켓몬 마스터 이다솜
// devgeon, 2024.08.27, C++17
// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_monsters = 0, num_queries = 0;
    string name = "", query = "";
    cin >> num_monsters >> num_queries;

    vector<string> names(num_monsters);
    unordered_map<string, int> numbers;

    for (int i = 1; i <= num_monsters; i++) {
        cin >> name;
        names[i - 1] = name;
        numbers[name] = i;
    }

    for (int i = 0; i < num_queries; i++) {
        cin >> query;
        if (query[0] < 'A') {
            cout << names[stoi(query) - 1] << '\n';
        } else {
            cout << numbers[query] << '\n';
        }
    }

    return 0;
}
