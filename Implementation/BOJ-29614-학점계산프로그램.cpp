// BOJ-29614 / 학점계산프로그램
// devgeon, 2024.04.15, C++17
// https://www.acmicpc.net/problem/29614

#include <iostream>

using namespace std;

int main() {
    char input;
    int count = 0;
    float gpa = .0f;

    while (true) {
        cin >> input;
        if (cin.eof()) {
            break;
        }

        switch (input) {
        case 'A':
            gpa += 1;
        case 'B':
            gpa += 1;
        case 'C':
            gpa += 1;
        case 'D':
            gpa += 1;
            break;
        case '+':
            gpa += 0.5f;
            count--;
            break;
        }
        count++;
    }
    gpa /= count;

    cout << gpa << endl;
    return 0;
}
