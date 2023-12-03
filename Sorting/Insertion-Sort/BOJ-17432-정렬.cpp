// BOJ-17432 / 정렬
// devgeon, 2023.12.03, C++17
// https://www.acmicpc.net/problem/17432

// 삽입 정렬을 역으로 수행하는 문제

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total_case = 0;
    int len = 0, temp = 0;
    long long cnt = 0;
    bool skip = true;
    vector<int> sequence;
    cin >> total_case;

    while (total_case > 0) {
        cin >> len >> cnt;
        skip = true;
        sequence.reserve(len);
        for (int i = 1; i <= len; i++) {
            sequence.push_back(i);
        }

        for (int left = 0, right = 1; right < len && cnt > 0; right++) {
            if (skip) {
                cnt -= right;
                if (cnt > 0) {
                    continue;
                } else if (cnt == 0) {
                    right++;
                }
                for (int i = 0; i < right; i++) {
                    sequence[i] = right - i;
                }
                skip = false;
                if (cnt < 0) {
                    cnt += right;
                } else {
                    break;
                }
            }

            left = right - 1;
            temp = sequence[right];
            for (; left > -1 && cnt > 0; left--) {
                if (sequence[left] < temp) {
                    sequence[left + 1] = sequence[left];
                    cnt--;
                } else {
                    left--;
                    break;
                }
            }
            sequence[left + 1] = temp;
        }

        for (int i = 0; i < len; i++) {
            cout << sequence[i];
            if (i == len - 1) {
                cout << '\n';
            } else {
                cout << ' ';
            }
        }

        sequence.clear();
        total_case--;
    }

    return 0;
}
