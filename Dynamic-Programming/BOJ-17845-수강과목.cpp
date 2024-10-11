// BOJ-17845 / 수강 과목
// devgeon, 2024.10.11, C++17
// https://www.acmicpc.net/problem/17845

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int max_time = 0, total_courses = 0, importance = 0, time = 0;
    cin >> max_time >> total_courses;

    vector<int> cache(max_time, 0);
    for (int c = 0; c < total_courses; c++) {
        cin >> importance >> time;
        for (int t = max_time - 1; t >= 0; t--) {
            if (time <= t + 1) {
                cache[t] = max(cache[t], cache[t - time] + importance);
            }
        }
    }
    cout << cache[max_time - 1] << endl;

    return 0;
}
