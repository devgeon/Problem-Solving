// BOJ-11004 / K번째 수
// devgeon, 2024.12.13, C++17
// https://www.acmicpc.net/problem/11004

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 0, idx = 0;
    cin >> len >> idx;
    idx--;

    vector<int> numbers(len, 0);
    for (int &n : numbers) {
        cin >> n;
    }

    sort(numbers.begin(), numbers.end());
    cout << numbers[idx] << endl;

    return 0;
}
