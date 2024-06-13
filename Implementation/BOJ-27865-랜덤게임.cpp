// BOJ-27865 / 랜덤게임
// devgeon, 2024.06.13, C++17
// https://www.acmicpc.net/problem/27865

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    char response = 'N';
    cin >> num;

    while (response == 'N') {
        cout << "? 1" << endl;
        cin >> response;
    }
    cout << "! 1" << endl;

    return 0;
}
