// BOJ-23306 / binary는 호남선
// devgeon, 2024.10.25, C++17
// https://www.acmicpc.net/problem/23306

#include <iostream>

using namespace std;

int main() {
    int num = 0, start = 0, end = 0;

    cin >> num;
    cout << "? 1" << endl;
    cin >> start;
    cout << "? " << num << endl;
    cin >> end;
    cout << "! " << end - start << endl;

    return 0;
}
