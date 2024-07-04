// BOJ-29991 / Fatigue-Fighting Vacation
// devgeon, 2024.07.04, C++17
// https://www.acmicpc.net/problem/29991

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer = 0;
    int disposition = 0, num_of_tiring = 0, num_of_invigorating = 0;
    cin >> disposition >> num_of_tiring >> num_of_invigorating;

    vector<int> tiring_activities(num_of_tiring);
    for (int &d : tiring_activities) {
        cin >> d;
    }
    vector<int> invigorating_activities(num_of_invigorating);
    for (int &d : invigorating_activities) {
        cin >> d;
    }

    for (auto t = tiring_activities.begin(),
              i = invigorating_activities.begin();;) {
        if (t != tiring_activities.end() && *t <= disposition) {
            disposition -= *t, answer++, t++;
            continue;
        }
        if (i == invigorating_activities.end()) {
            break;
        }
        disposition += *i, answer++, i++;
    }
    cout << answer << endl;

    return 0;
}
