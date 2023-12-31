// BOJ-01924 / 2007년
// devgeon, 2023.12.31, C++17
// https://www.acmicpc.net/problem/1924

#include <iostream>

using namespace std;

int main() {
    int date = 0, month = 0, day = 0;
    int duration[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day_of_the_week[] = {"SUN", "MON", "TUE", "WED",
                                "THU", "FRI", "SAT"};

    cin >> month >> day;

    for (int i = 0; i < month - 1; i++) {
        date += duration[i];
    }
    date += day;

    cout << day_of_the_week[date % 7] << endl;
    return 0;
}
