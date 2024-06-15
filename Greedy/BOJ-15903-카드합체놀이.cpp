// BOJ-15903 / 카드 합체 놀이
// devgeon, 2024.06.15, C++17
// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, merge = 0;
    long long answer = 0;
    cin >> num >> merge;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0, input = 0; i < num; i++) {
        cin >> input;
        pq.push(input);
        answer += input;
    }

    for (long long i = 0, sum = 0; i < merge; i++) {
        sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        pq.push(sum);
        pq.push(sum);
        answer += sum;
    }
    cout << answer << endl;

    return 0;
}
