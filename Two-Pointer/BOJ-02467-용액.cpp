// BOJ-02467 / 용액
// devgeon, 2024.11.10, C++17
// https://www.acmicpc.net/problem/2467

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Answer {
  public:
    int sum = (1U << 31) - 1, left_value = 0, right_value = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, sum = 0;
    cin >> num;

    Answer answer;
    vector<int> seq(num, 0);
    vector<int>::iterator left, right;
    for (int &n : seq) {
        cin >> n;
    }
    sort(seq.begin(), seq.end());

    left = seq.begin(), right = --seq.end();
    while (left < right) {
        sum = *left + *right;
        if (abs(sum) < answer.sum) {
            answer.left_value = *left, answer.right_value = *right;
            answer.sum = abs(sum);
        }
        sum > 0 ? right-- : left++;
    }

    cout << answer.left_value << ' ' << answer.right_value << endl;

    return 0;
}
