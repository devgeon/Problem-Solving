// BOJ-14002 / 가장 긴 증가하는 부분 수열 4
// devgeon, 2024.05.05, C++17
// https://www.acmicpc.net/problem/14002

#include <iostream>
#include <vector>

using namespace std;

class CacheItem {
  public:
    int count = 1;
    int next = -1;
};

int main() {
    int num = 0, max_len_idx = 0;
    cin >> num;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    vector<CacheItem> cache(num);
    for (int i = 0; i < num; i++) {
        cache[i].count = 1;
        cache[i].next = i;
    }

    for (int i = num - 1; i > -1; i--) {
        for (int j = i - 1; j > -1; j--) {
            if (seq[j] >= seq[i]) {
                continue;
            }
            if (cache[j].count < cache[i].count + 1) {
                cache[j].count = cache[i].count + 1;
                cache[j].next = i;
            }
        }
        if (cache[max_len_idx].count < cache[i].count) {
            max_len_idx = i;
        }
    }

    cout << cache[max_len_idx].count << '\n';
    for (int i = max_len_idx;; i = cache[i].next) {
        cout << seq[i] << ' ';
        if (i == cache[i].next) {
            break;
        }
    }
    cout << endl;

    return 0;
}
