// BOJ-14501 / 퇴사
// devgeon, 2024.03.12, C++17
// https://www.acmicpc.net/problem/14501

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0;
    cin >> num;

    vector<int> time(num, 0);
    vector<int> profit(num, 0);
    vector<int> answer(num + 1, 0);
    for (int i = 0; i < num; i++) {
        cin >> time[i] >> profit[i];
    }

    for (int i = num - 1; i >= 0; i--) {
        answer[i] = answer[i + 1];
        if (i + time[i] > num) {
            continue;
        }
        answer[i] = max(answer[i], answer[i + time[i]] + profit[i]);
    }

    cout << answer[0] << endl;

    return 0;
}
