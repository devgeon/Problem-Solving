// BOJ-15810 / 풍선 공장
// devgeon, 2024.04.06, C++17
// https://www.acmicpc.net/problem/15810

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long count(vector<int> &time_per_ballons, long long time);
long long solve(vector<int> &time_per_ballons, int required);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_staff = 0, num_of_ballons = 0;
    cin >> num_of_staff >> num_of_ballons;

    vector<int> time_per_ballons(num_of_staff, 0);
    for (int &time : time_per_ballons) {
        cin >> time;
    }

    cout << solve(time_per_ballons, num_of_ballons) << endl;

    return 0;
}

long long count(vector<int> &time_per_ballons, long long time) {
    long long answer = 0LL;

    for (int t : time_per_ballons) {
        if (t > time) {
            continue;
        }
        answer += time / t;
    }

    return answer;
}

long long solve(vector<int> &time_per_ballons, int required) {
    const long long MAX = 1'000'000'000'000LL;
    long long minimum = 0LL, maximum = MAX, mean = 0LL;

    while (minimum < maximum) {
        mean = (minimum + maximum) / 2;
        if (required <= count(time_per_ballons, mean)) {
            maximum = mean;
        } else {
            minimum = mean + 1;
        }
    }

    return maximum;
}
