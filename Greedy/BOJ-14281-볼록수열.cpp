// BOJ-14281 / 볼록 수열
// devgeon, 2024.03.08, C++17
// https://www.acmicpc.net/problem/14281

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size = 0, temp = 0;
    long long answer = 0;
    bool done = false;

    cin >> size;

    vector<int> sequence(size, 0);
    for (int &num : sequence) {
        cin >> num;
    }

    while (!done) {
        done = true;
        for (int i = 1; i < size - 1; i++) {
            temp = sequence[i - 1] + sequence[i + 1] - 2 * sequence[i];
            if (temp >= 0) {
                continue;
            }
            temp = (temp + 1) / 2 - 1;
            sequence[i] += temp;
            answer -= temp;
            done = false;
        }
    }

    cout << answer << endl;

    return 0;
}
