// BOJ-30469 / 호반우가 학교에 지각한 이유 2
// devgeon, 2024.12.06, C++17
// https://www.acmicpc.net/problem/30469

#include <iostream>

using namespace std;

int main() {
    int start = 0, end = 0, len = 0;
    cin >> start >> end >> len;

    string answer = to_string(start);

    switch (start % 10) {
    case 1:
        answer.append("11");
        break;
    case 3:
        answer.append("11");
        break;
    case 7:
        answer.append("11");
        break;
    case 9:
        answer.append("71");
        break;
    default:
        cout << -1 << endl;
        return 0;
    }

    for (int i = 7; i < len; i++) {
        answer.push_back('1');
    }

    switch (end / 10) {
    case 1:
        answer.append("1");
        break;
    case 3:
        answer.append("1");
        break;
    case 7:
        answer.append("1");
        break;
    case 9:
        answer.append("1");
        break;
    default:
        cout << -1 << endl;
        return 0;
    }

    answer.append(to_string(end));
    cout << answer << endl;

    return 0;
}
