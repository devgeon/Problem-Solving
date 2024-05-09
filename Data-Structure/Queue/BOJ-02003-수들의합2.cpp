// BOJ-02003 / 수들의 합 2
// devgeon, 2024.05.09, C++17
// https://www.acmicpc.net/problem/2003

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, target = 0, sum = 0, count = 0, input = 0;
    cin >> num >> target;

    queue<int> interval;
    for (int i = 0; i < num; i++) {
        cin >> input;
        sum += input;
        interval.push(input);
        while (sum > target) {
            sum -= interval.front();
            interval.pop();
        }
        if (sum == target) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
