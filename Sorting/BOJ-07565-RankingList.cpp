// BOJ-07565 / Ranking List
// devgeon, 2024.07.03, C++17
// https://www.acmicpc.net/problem/7565

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int scenarios = 0;
    cin >> scenarios;

    while (scenarios--) {
        solve();
    }

    return 0;
}

void solve() {
    int problem = 0, time = 0;
    string accepted = "", team_name = "";
    
    int total_teams = 0, total_problems = 0, total_submissions = 0;
    unordered_map<string, int> total_time;
    unordered_map<string, int> total_solved;
    unordered_map<string, vector<int>> attempts;

    cin >> total_teams;
    vector<string> team_names(total_teams, "");
    for (string &name : team_names) {
        cin >> name;
    }
    cin >> total_problems >> total_submissions;
    for (string name : team_names) {
        attempts[name] = vector<int>(total_problems, 0);
    }

    while (total_submissions--) {
        cin >> problem >> time >> accepted >> team_name;
        if (attempts[team_name][problem - 1] < 0) {
            continue;
        }
        if (accepted == "No") {
            attempts[team_name][problem - 1]++;
            continue;
        }
        total_solved[team_name]++;
        total_time[team_name] += time;
        total_time[team_name] += 20 * attempts[team_name][problem - 1];
        attempts[team_name][problem - 1] = -1;
    }

    stable_sort(team_names.begin(), team_names.end(),
                [&total_solved, &total_time](const string &team1,
                                             const string &team2) -> bool {
                    if (total_solved[team1] > total_solved[team2]) {
                        return true;
                    }
                    if (total_solved[team1] == total_solved[team2] &&
                        total_time[team1] < total_time[team2]) {
                        return true;
                    }
                    return false;
                });

    for (int i = 0, rank = 1, solved = total_solved[team_names[0]],
             time = total_time[team_names[0]]; i < total_teams; i++) {
        team_name = team_names[i];
        cout << setw(2);
        if (total_solved[team_name] == solved &&
            total_time[team_name] == time) {
            cout << rank;
        } else {
            rank = i + 1;
            cout << rank;
        }
        solved = total_solved[team_name];
        time = total_time[team_name];
        cout << ". ";
        cout << setw(8) << std::left << team_name << ' ';
        cout << std::right << solved << ' ';
        cout << setw(4) << time << '\n';
    }
    cout << '\n';
}
