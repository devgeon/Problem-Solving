// BOJ-17298 / 오큰수
// devgeon, 2024.05.10, C++17
// https://www.acmicpc.net/problem/17298

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    vector<int> answer;
    answer.reserve(num);
    stack<int> stack;

    for (auto it = seq.rbegin(); it != seq.rend(); it++) {
        while (!stack.empty() && stack.top() <= *it) {
            stack.pop();
        }
        if (stack.empty()) {
            answer.push_back(-1);
        } else {
            answer.push_back(stack.top());
        }
        stack.push(*it);
    }

    reverse(answer.begin(), answer.end());
    for (int n : answer) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
