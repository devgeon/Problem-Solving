// BOJ-02659 / 십자카드 문제
// devgeon, 2024.12.20, C++17
// https://www.acmicpc.net/problem/2659

#include <iostream>

using namespace std;

string get_min(const string &num);
int solve(const string &target);
int _solve(const string &target, string &cur, const int idx);

int main() {
    string target = "", cur = "1111";
    for (int i = 0; i < 3; i++) {
        target.push_back(cin.get());
        cin.get();
    }
    target.push_back(cin.get());

    cout << solve(get_min(target)) << endl;

    return 0;
}

inline string get_min(const string &num) {
    string min_num = num;
    for (int i = 0, len = num.size(); i < len; i++) {
        min_num = min(min_num, num.substr(i, len - i) + num.substr(0, i));
    }
    return min_num;
}

inline int solve(const string &target) {
    string temp = "1111";
    if (target == temp) {
        return 1;
    }
    return _solve(target, temp, 0);
}

int _solve(const string &target, string &cur, const int idx) {
    int cnt = 0, len = cur.size();
    if (idx == len) {
        return (int)(cur == get_min(cur));
    }

    for (int i = 1; i < 10 && cur != target; i++) {
        cur[idx] = '0' + (char)i;
        cnt += _solve(target, cur, idx + 1);
    }
    if (cur != target) {
        cur[idx] = '1';
    }

    return cnt;
}
