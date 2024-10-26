// BOJ-11899 / 괄호 끼워넣기
// devgeon, 2024.10.26, C++17
// https://www.acmicpc.net/problem/11899

#include <iostream>

using namespace std;

int main() {
    int sp = 0, cnt = 0;
    char ch = 0;

    while (cin >> ch) {
        (ch == '(' ? sp++ : (sp > 0 ? sp-- : cnt++));
    }
    cnt += sp;
    cout << cnt << endl;

    return 0;
}
