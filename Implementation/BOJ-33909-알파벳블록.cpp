// BOJ-33909 / 알파벳 블록
// devgeon, 2025.09.21, C++17
// https://www.acmicpc.net/problem/33909

#include <iostream>

using namespace std;

int main() {
    int s = 0, c = 0, o = 0, n = 0;
    cin >> s >> c >> o >> n;

    s += n;
    o += c / 2;
    cout << min(s / 3, o / 3) << endl;

    return 0;
}
