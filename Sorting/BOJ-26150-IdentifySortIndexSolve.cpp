// BOJ-26150 / Identify, Sort, Index, Solve
// devgeon, 2024.11.21, C++17
// https://www.acmicpc.net/problem/26150

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Problem {
  private:
    int num;
    int level;
    string title;

  public:
    Problem(const int num = -1, const int level = -1, const string title = "")
        : num(num), level(level), title(title) {}

    bool operator<(const Problem &prob) const {
        return this->num < prob.num;
    }

    friend istream &operator>>(istream &in, Problem &prob) {
        in >> prob.title >> prob.num >> prob.level;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Problem &prob) {
        out << (char)toupper(prob.title[prob.level - 1]);
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<Problem> problems(num);
    for (Problem &prob : problems) {
        cin >> prob;
    }
    sort(problems.begin(), problems.end());

    for (const Problem &prob : problems) {
        cout << prob;
    }
    cout << endl;

    return 0;
}
