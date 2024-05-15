// BOJ-01931 / 회의실 배정
// devgeon, 2024.05.15, C++17
// https://www.acmicpc.net/problem/1931

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Meeting {
  public:
    int start = 0;
    int finish = 0;

    friend istream &operator>>(istream &in, Meeting &meeting) {
        in >> meeting.start >> meeting.finish;
        return in;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, time = 0, count = 0;
    cin >> num;

    vector<Meeting> meetings(num);
    for (Meeting &meeting : meetings) {
        cin >> meeting;
    }
    sort(meetings.begin(), meetings.end(),
         [](const Meeting &a, const Meeting &b) -> bool {
             return a.start < b.start;
         });
    stable_sort(meetings.begin(), meetings.end(),
                [](const Meeting &a, const Meeting &b) -> bool {
                    return a.finish < b.finish;
                });

    for (Meeting meeting : meetings) {
        if (meeting.start < time) {
            continue;
        }
        time = meeting.finish;
        count++;
    }

    cout << count << endl;
    return 0;
}
