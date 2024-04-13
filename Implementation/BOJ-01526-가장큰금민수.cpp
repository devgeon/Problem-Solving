// BOJ-01526 / 가장 큰 금민수
// devgeon, 2024.04.13, C++17
// https://www.acmicpc.net/problem/1526

#include <iostream>
#include <vector>

using namespace std;

int main() {
    char input = 0;
    bool skip = false;

    vector<char> num;
    vector<char> answer;

    while (true) {
        cin >> input;
        if (cin.eof()) {
            break;
        }
        num.push_back(input);
    }

    for (char c : num) {
        if (skip) {
            answer.push_back('7');
            continue;
        }
        if (c == '7' || c == '4') {
            answer.push_back(c);
            continue;
        } else if (c > '7') {
            answer.push_back('7');
        } else if (c > '4' && c < '7') {
            answer.push_back('4');
        } else if (!answer.empty()) {
            if (answer.back() == '4') {
                answer.back() = '7';
            } else {
                answer.back() = '4';
                answer.push_back('7');
            }
        }
        skip = true;
    }

    for (char c : answer) {
        cout << c;
    }
    cout << endl;

    return 0;
}
