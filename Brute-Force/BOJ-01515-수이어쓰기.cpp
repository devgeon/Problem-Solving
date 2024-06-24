// BOJ-01515 / 수 이어 쓰기
// devgeon, 2024.06.24, C++17
// https://www.acmicpc.net/problem/1515

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int answer = 0;
    char curr = '0', input = 0;
    vector<int> temp;
    queue<char> queue;

    while (true) {
        cin >> input;
        if (cin.eof()) {
            break;
        }
        do {
            if (queue.empty()) {
                answer++;
                for (int t = answer; t > 0; t /= 10) {
                    temp.push_back(t % 10);
                }
                for (auto it = temp.rbegin(); it != temp.rend(); it++) {
                    queue.push(*it + '0');
                }
                temp.clear();
            }
            curr = queue.front();
            queue.pop();
        } while (curr != input);
    }
    cout << answer << endl;

    return 0;
}
