// BOJ-13274 / 수열
// devgeon, 2024.10.24, C++17
// https://www.acmicpc.net/problem/13274

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size = 0, total_queries = 0;
    cin >> size >> total_queries;

    vector<long long> seq(size);
    for (long long &n : seq) {
        cin >> n;
    }
    sort(seq.begin(), seq.end());

    while (total_queries--) {
        int left = 0, right = 0, num = 0;
        cin >> left >> right >> num;

        for (int i = left - 1; i < right; i++) {
            seq[i] += num;
        }

        for (int i = 1; i < size; i++) {
            for (int j = i; j > 0; j--) {
                if (seq[j - 1] <= seq[j]) {
                    break;
                }
                swap(seq[j - 1], seq[j]);
            }
        }
    }

    for (long long n : seq) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
