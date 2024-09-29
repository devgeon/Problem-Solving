// BOJ-30805 / 사전 순 최대 공통 부분 수열
// devgeon, 2024.09.29, C++17
// https://www.acmicpc.net/problem/30805

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &seq, vector<int> &sorted_index, int &len);

int main() {
    int len_a = 0, len_b = 0, idx_a = 0, idx_b = 0, max_idx_a = 0, max_idx_b = 0;
    vector<int> seq_a, seq_b, sort_idxes_a, sort_idxes_b, answer;

    input(seq_a, sort_idxes_a, len_a);
    input(seq_b, sort_idxes_b, len_b);

    while (idx_a < len_a && idx_b < len_b) {
        while (max_idx_a < len_a && max_idx_b < len_b) {
            if (seq_a[sort_idxes_a[max_idx_a]] > seq_b[sort_idxes_b[max_idx_b]] ||
                sort_idxes_a[max_idx_a] < idx_a) {
                max_idx_a++;
            } else if (seq_a[sort_idxes_a[max_idx_a]] < seq_b[sort_idxes_b[max_idx_b]] ||
                       sort_idxes_b[max_idx_b] < idx_b) {
                max_idx_b++;
            } else {
                break;
            }
        }
        if (!(max_idx_a < len_a && max_idx_b < len_b)) {
            break;
        }
        answer.push_back(seq_a[sort_idxes_a[max_idx_a]]);

        while (idx_a < len_a) {
            if (seq_a[idx_a++] == seq_a[sort_idxes_a[max_idx_a]]) {
                break;
            }
        }
        while (idx_b < len_b) {
            if (seq_b[idx_b++] == seq_b[sort_idxes_b[max_idx_b]]) {
                break;
            }
        }
        max_idx_a++, max_idx_b++;
    }

    cout << answer.size() << '\n';
    for (int n : answer) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}

void input(vector<int> &seq, vector<int> &sorted_index, int &len) {
    cin >> len;
    seq.reserve(len);
    sorted_index.reserve(len);
    for (int i = 0, input = 0; i < len; i++) {
        cin >> input;
        seq.push_back(input);
        sorted_index.push_back(i);
    }
    stable_sort(sorted_index.begin(), sorted_index.end(),
                [&seq](int i, int j) -> bool { return seq[i] > seq[j]; });
}
