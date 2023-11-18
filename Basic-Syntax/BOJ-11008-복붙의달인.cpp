// BOJ-11008 / 복붙의 달인
// devgeon, 2023.11.18, C++17
// https://www.acmicpc.net/problem/11008

#include <iostream>

using namespace std;

int main() {
    int total_case = 0, elapsed_time = 0, tmp_idx = 0;
    string target = "", clipboard = "";

    cin >> total_case;

    for (int case_num = 0; case_num < total_case; case_num++) {
        elapsed_time = 0;
        cin >> target >> clipboard;

        while ((tmp_idx = target.find(clipboard)) != string::npos) {
            target.erase(tmp_idx, clipboard.length());
            elapsed_time++;
        }
        elapsed_time += target.length();
        cout << elapsed_time << "\n";
    }

    return 0;
}
