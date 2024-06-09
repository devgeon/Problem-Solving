// BOJ-31747 / 점호
// devgeon, 2024.06.09, C++17
// https://www.acmicpc.net/problem/31747

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, limit = 0, first_grade = 0, second_grade = 0, time = 0;
    cin >> num >> limit;

    for (int i = 0, input = 0; i < num; i++) {
        cin >> input;
        if (first_grade + second_grade < limit - 1) {
            input == 1 ? first_grade++ : second_grade++;
            continue;
        }
        if (input == 1 && second_grade > 0) {
            second_grade--;
        } else if (input == 2 && first_grade > 0) {
            first_grade--;
        }
        time++;
    }
    time += max(first_grade, second_grade);
    cout << time << endl;

    return 0;
}
