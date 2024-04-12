// BOJ-01725 / 히스토그램
// devgeon, 2024.04.12, C++17
// https://www.acmicpc.net/problem/1725

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, freq = 0, answer = 0;
    cin >> num;

    stack<int> stack({-1});
    vector<int> histogram(num, 0);
    for (int &n : histogram) {
        cin >> n;
    }

    for (int i = 0; i < num; i++) {
        while (stack.size() > 1 && histogram[i] < histogram[stack.top()]) {
            freq = histogram[stack.top()];
            stack.pop();
            answer = max(freq * (i - stack.top() - 1), answer);
        }
        stack.push(i);
    }
    while (stack.size() > 1) {
        freq = histogram[stack.top()];
        stack.pop();
        answer = max(freq * (num - stack.top() - 1), answer);
    }

    cout << answer << endl;

    return 0;
}
