// BOJ-25206 / 너의 평점은
// devgeon, 2024.07.22, C++17
// https://www.acmicpc.net/problem/25206

#include <iostream>

using namespace std;

int main() {
    string course = "";
    double credit = 0, grade = 0, total_credit = 0, total_grade = 0;

    while (true) {
        cin >> course;
        if (cin.eof()) {
            break;
        }
        cin >> credit;
        cin.get();
        grade = 4 - (cin.get() - 'A');
        if (grade < -1) {
            continue;
        } else if (grade == -1) {
            grade = 0;
        } else if (cin.get() == '+') {
            grade += 0.5;
        }
        total_credit += credit;
        total_grade += grade * credit;
    }
    cout << total_grade / total_credit << endl;

    return 0;
}
