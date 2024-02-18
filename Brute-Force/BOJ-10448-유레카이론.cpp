// BOJ-10448 / 유레카 이론
// devgeon, 2024.02.18, C++17
// https://www.acmicpc.net/problem/10448

#include <iostream>
#include <vector>

using namespace std;

bool check(int number, vector<int> &triangular_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1000;
    int total_cases = 0, number = 1, temp = 0;
    vector<int> triangular_number;

    while (true) {
        temp = number * (number + 1) / 2;
        if (temp > MAX) {
            break;
        }
        triangular_number.push_back(temp);
        number++;
    }

    cin >> total_cases;
    for (int c = 1; c <= total_cases; c++) {
        cin >> number;
        cout << (check(number, triangular_number) ? 1 : 0) << "\n";
    }

    return 0;
}

bool check(int number, vector<int> &triangular_number) {
    for (int a : triangular_number) {
        for (int b : triangular_number) {
            for (int c : triangular_number) {
                if (a + b + c == number) {
                    return true;
                }
            }
        }
    }
    return false;
}
