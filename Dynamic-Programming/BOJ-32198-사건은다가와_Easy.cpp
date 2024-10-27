// BOJ-32198 / 사건은 다가와 (Easy)
// devgeon, 2024.10.27, C++17
// https://www.acmicpc.net/problem/32198

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Event {
  public:
    int time = 0, lower_bound = 0, upper_bound = 0;

    Event(int time, int lower_bound, int upper_bound) {
        this->time = time;
        this->lower_bound = lower_bound;
        this->upper_bound = upper_bound;
    }

    bool operator>(const Event &event) const {
        return this->time > event.time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int DMAX = 1'000, DMIN = -1'000, DRANGE = DMAX - DMIN + 1,
              INF = (1 << 31) - 2;
    int num = 0, tmax = 0, answer = INF;
    cin >> num;

    vector<Event> events;
    events.reserve(num);
    for (int i = 0, time = 0, lower_bound = 0, upper_bound = 0; i < num; i++) {
        cin >> time >> lower_bound >> upper_bound;
        events.emplace_back(time, lower_bound - DMIN + 1, upper_bound - DMIN);
    }
    sort(events.begin(), events.end(), greater());
    tmax = events[0].time;

    vector<vector<int>> dists(2, vector<int>(DRANGE + 2, INF));
    dists[0][-DMIN] = 0;
    for (int t = 1; t <= tmax; t++) {
        const Event &event = *events.rbegin();
        for (int i = 1; i <= DRANGE; i++) {
            dists[t & 1][i] = min({
                dists[(t - 1) & 1][i - 1] + 1,
                dists[(t - 1) & 1][i],
                dists[(t - 1) & 1][i + 1] + 1
            });
            dists[t & 1][i] = (dists[t & 1][i] > INF ? INF : dists[t & 1][i]);
        }
        if (t == event.time) {
            for (int i = event.lower_bound; i < event.upper_bound; i++) {
                dists[t & 1][i] = INF;
            }
            events.pop_back();
        }
    }

    for (const int dist : dists[tmax & 1]) {
        answer = min(dist, answer);
    }
    answer = (answer == INF ? -1 : answer);
    cout << answer << endl;

    return 0;
}
