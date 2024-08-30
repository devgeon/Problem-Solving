// BOJ-17952 / 과제는 끝나지 않아!
// devgeon, 2024.08.30, C++17
// https://www.acmicpc.net/problem/17952

#include <iostream>
#include <stack>

using namespace std;

class Assignment {
  public:
    int score = 0;
    int time_left = 0;

    Assignment(int score, int time_left) {
        this->score = score;
        this->time_left = time_left;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_time = 0, given = 0, score = 0, time_left = 0, answer = 0;
    stack<Assignment> stack;
    cin >> total_time;

    while (total_time--) {
        cin >> given;
        if (given == 1) {
            if (time_left > 0) {
                stack.emplace(score, time_left);
            }
            cin >> score >> time_left;
        }

        time_left--;
        if (time_left == 0) {
            answer += score;
            if (stack.size() > 0) {
                score = stack.top().score;
                time_left = stack.top().time_left;
                stack.pop();
            }
        }
    }

    cout << answer << endl;
    return 0;
}
