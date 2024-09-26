// BOJ-01541 / 잃어버린 괄호
// devgeon, 2024.09.26, C++17
// https://www.acmicpc.net/problem/1541

#include <iostream>

using namespace std;

int main() {
    int num = 0, answer = 0;
    char oper = 0;
    bool add = true;
    cin >> answer;

    while (true) {
        cin >> oper;
        if (cin.eof()) {
            break;
        }
        cin >> num;
        if (add && oper == '-') {
            add = false;
        }
        answer += (add ? num : -num);
    }
    cout << answer << endl;

    return 0;
}
