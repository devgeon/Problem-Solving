// BOJ-11053 / 가장 긴 증가하는 부분 수열
// devgeon, 2024.05.03, C++17
// https://www.acmicpc.net/problem/11053

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 0, answer = 1;
    cin >> num;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    vector<int> count(num, 1);

    for (int i = 1; i < num; i++) {
        for (int j = i - 1; j > -1; j--) {
            if (seq[i] <= seq[j]) {
                continue;
            }
            count[i] = max(count[i], count[j] + 1);
        }
        answer = max(count[i], answer);
    }

    cout << answer << endl;
    return 0;
}
