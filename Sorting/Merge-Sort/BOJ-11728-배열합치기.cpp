// BOJ-11728 / 배열 합치기
// devgeon, 2024.05.22, C++17
// https://www.acmicpc.net/problem/11728

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len_a = 0, len_b = 0;
    cin >> len_a >> len_b;

    vector<int> vec_a(len_a);
    vector<int> vec_b(len_b);
    for (int &n : vec_a) {
        cin >> n;
    }
    for (int &n : vec_b) {
        cin >> n;
    }

    auto it_a = vec_a.begin(), it_b = vec_b.begin();
    while (it_a != vec_a.end() && it_b != vec_b.end()) {
        if (*it_a < *it_b) {
            cout << *it_a << ' ';
            it_a++;
        } else {
            cout << *it_b << ' ';
            it_b++;
        }
    }
    while (it_a != vec_a.end()) {
        cout << *it_a << ' ';
        it_a++;
    }
    while (it_b != vec_b.end()) {
        cout << *it_b << ' ';
        it_b++;
    }

    return 0;
}
