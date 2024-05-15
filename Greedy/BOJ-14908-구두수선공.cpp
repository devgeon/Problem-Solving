// BOJ-14908 / 구두 수선공
// devgeon, 2024.05.15, C++17
// https://www.acmicpc.net/problem/14908

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Task {
  public:
    int id = 0;
    int time = 0;
    int late_fee = 0;

    Task() {
        static int new_id = 1;

        this->id = new_id;
        new_id++;
    }
};

bool compare_tasks(const Task &a, const Task &b) {
    return (a.time * b.late_fee < b.time * a.late_fee);
}

int main() {
    int num = 0, time = 0, late_fee = 0;
    cin >> num;

    vector<Task> tasks(num);
    for (Task &task : tasks) {
        cin >> task.time >> task.late_fee;
    }
    stable_sort(tasks.begin(), tasks.end(), compare_tasks);

    for (Task task : tasks) {
        cout << task.id << ' ';
    }
    cout << endl;

    return 0;
}
