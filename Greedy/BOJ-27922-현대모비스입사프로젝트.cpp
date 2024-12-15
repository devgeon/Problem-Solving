// BOJ-27922 / 현대모비스 입사 프로젝트
// devgeon, 2024.12.15, C++17
// https://www.acmicpc.net/problem/27922

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int simulate(int limit, vector<int> &idx,
             const vector<int> &lec1, const vector<int> &lec2) {
    int sum = 0;
    sort(idx.begin(), idx.end(),
         [&lec1, &lec2](const int i, const int j) -> bool {
             return lec1[i] + lec2[i] > lec1[j] + lec2[j];
         });
    for (int i = 0; i < limit; i++) {
        sum += lec1[idx[i]] + lec2[idx[i]];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, limit = 0, answer = 0;
    cin >> num >> limit;

    vector<int> idx(num, 0), comm(num, 0), algo(num, 0), mech(num, 0);
    for (int i = 0; i < num; i++) {
        idx[i] = i;
        cin >> comm[i] >> algo[i] >> mech[i];
    }

    answer = max(answer, simulate(limit, idx, comm, algo));
    answer = max(answer, simulate(limit, idx, algo, mech));
    answer = max(answer, simulate(limit, idx, comm, mech));
    cout << answer << endl;

    return 0;
}
