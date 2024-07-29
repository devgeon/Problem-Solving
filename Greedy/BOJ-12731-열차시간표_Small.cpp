// BOJ-12731 / 열차 시간표(Small)
// devgeon, 2024.07.29, C++17
// https://www.acmicpc.net/problem/12731

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Time {
  public:
    char from = 0, to = 0;
    int departure_time = 0, arrival_time = 0;
};

istream &operator>>(istream &in, Time &time) {
    int hour = 0, minute = 0;
    in >> hour, in.get(), in >> minute;
    time.departure_time = hour * 60 + minute;
    in >> hour, in.get(), in >> minute;
    time.arrival_time = hour * 60 + minute;
    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_cases = 0, turn_time = 0;
    int num_of_schedules_from_a = 0, num_of_schedules_from_b = 0;
    int count_trains_from_a = 0, count_trains_from_b = 0;
    Time input_time;
    vector<Time> timetable;
    priority_queue<int, vector<int>, greater<int>> waiting_trains_at_a, waiting_trains_at_b;

    cin >> num_of_cases;
    for (int i = 1; i <= num_of_cases; i++) {
        timetable.clear();
        count_trains_from_a = 0, count_trains_from_b = 0;
        waiting_trains_at_a = priority_queue<int, vector<int>, greater<int>>();
        waiting_trains_at_b = priority_queue<int, vector<int>, greater<int>>();

        cin >> turn_time >> num_of_schedules_from_a >> num_of_schedules_from_b;
        for (int j = 0, end = num_of_schedules_from_a + num_of_schedules_from_b; j < end; j++) {
            cin >> input_time;
            if (j < num_of_schedules_from_a) {
                input_time.from = 'a', input_time.to = 'b';
            } else {
                input_time.from = 'b', input_time.to = 'a';
            }
            timetable.emplace_back(input_time);
        }
        sort(timetable.begin(), timetable.end(), [](Time &a, Time &b) -> bool {
            return a.departure_time < b.departure_time;
        });

        for (Time time : timetable) {
            if (time.from == 'a') {
                if (waiting_trains_at_a.size() > 0 && waiting_trains_at_a.top() <= time.departure_time) {
                    waiting_trains_at_a.pop();
                } else {
                    count_trains_from_a++;
                }
                waiting_trains_at_b.push(time.arrival_time + turn_time);
            } else {
                if (waiting_trains_at_b.size() > 0 && waiting_trains_at_b.top() <= time.departure_time) {
                    waiting_trains_at_b.pop();
                } else {
                    count_trains_from_b++;
                }
                waiting_trains_at_a.push(time.arrival_time + turn_time);
            }
        }
        cout << "Case #" << i << ": " << count_trains_from_a << ' ' << count_trains_from_b << '\n';
    }

    return 0;
}
