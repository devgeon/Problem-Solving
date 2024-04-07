// BOJ-02805 / 나무 자르기
// devgeon, 2024.04.07, C++17
// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>

using namespace std;

long long cut_down_trees(vector<int> &height_of_trees, int height);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int low = 0, high = 0, mid = 0;
    int num_of_trees = 0, required = 0, max_value = 0;
    cin >> num_of_trees >> required;

    vector<int> height_of_trees(num_of_trees, 0);
    for (int &height : height_of_trees) {
        cin >> height;
        max_value = max(height, max_value);
    }

    high = max_value;
    while (low < high) {
        mid = (high + low + 1) / 2;
        if (cut_down_trees(height_of_trees, mid) < required) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }

    cout << low << endl;

    return 0;
}

long long cut_down_trees(vector<int> &height_of_trees, int height) {
    long long result = 0;

    for (int i = 0; i < height_of_trees.size(); i++) {
        result += max(height_of_trees[i] - height, 0);
    }

    return result;
}
