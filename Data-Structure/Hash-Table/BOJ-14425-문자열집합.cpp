// BOJ-14425 / 문자열 집합
// devgeon, 2024.07.17, C++17
// https://www.acmicpc.net/problem/14425

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size = 0, query_size = 0, count = 0;
    string word = "";
    cin >> size >> query_size;

    unordered_set<string> set;
    for (int i = 0; i < size; i++) {
        cin >> word;
        set.insert(word);
    }

    for (int i = 0; i < query_size; i++) {
        cin >> word;
        if (set.find(word) != set.end()) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}
