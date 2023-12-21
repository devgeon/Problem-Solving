// BOJ-12919 / A와 B 2
// devgeon, 2023.12.21, C++17
// https://www.acmicpc.net/problem/12919

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool reverse_operation(const string &source, const string &target,
                       bool reversed);

int main() {
    string source = "", target = "";
    cin >> source >> target;
    bool result = false;

    result = reverse_operation(source, target, false);

    if (result) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}

bool reverse_operation(const string &source, const string &target,
                       bool reversed) {
    bool result = false;

    if (source.size() == target.size()) {
        string new_target = target;
        if (reversed) {
            reverse(new_target.begin(), new_target.end());
        }
        if (source == new_target) {
            return true;
        }
        return false;
    }

    if (target[(reversed ? 0 : target.size() - 1)] == 'A') {
        result |= reverse_operation(
            source, target.substr((reversed ? 1 : 0), target.size() - 1),
            reversed);
    }
    if (target[(reversed ? target.size() - 1 : 0)] == 'B') {
        result |= reverse_operation(
            source, target.substr((reversed ? 0 : 1), target.size() - 1),
            !reversed);
    }
    return result;
}
