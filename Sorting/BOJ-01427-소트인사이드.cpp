// BOJ-01427 / 소트인사이드
// devgeon, 2024.04.20, C++17
// https://www.acmicpc.net/problem/1427

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string num = "";
    cin >> num;

    sort(num.begin(), num.end(), greater());
    cout << num << endl;

    return 0;
}
