// BOJ-19621 / 회의실 배정 2
// devgeon, 2024.10.09, C++17
// https://www.acmicpc.net/problem/19621

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total_meetings = 0;
    cin >> total_meetings;

    vector<int> attendee_counts(total_meetings, 0);
    for (int &n : attendee_counts) {
        cin.ignore(11 + 1, ' ');
        cin.ignore(11, ' ');
        cin >> n;
    }

    vector<int> cache(3, 0);
    for (int i = 0; i < total_meetings; i++) {
        cache[i % 3] = max(cache[(i + 2) % 3], cache[(i + 1) % 3] + attendee_counts[i]);
    }
    cout << cache[(total_meetings - 1) % 3] << endl;

    return 0;
}
