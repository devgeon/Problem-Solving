// BOJ-12015 / 가장 긴 증가하는 부분 수열 2
// devgeon, 2024.11.07, C++17
// https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, size = 0;
    cin >> size;

    vector<int> cache;
    vector<int>::iterator it;

    for (int i = 0; i < size; i++) {
        cin >> num;
        it = lower_bound(cache.begin(), cache.end(), num);
        if (it != cache.end()) {
            *it = num;
        } else {
            cache.push_back(num);
        }
    }
    cout << cache.size() << endl;

    return 0;
}
