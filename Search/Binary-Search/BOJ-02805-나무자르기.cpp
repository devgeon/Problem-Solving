// BOJ-02805 / 나무 자르기
// devgeon, 2024.03.10, C++17
// https://www.acmicpc.net/problem/2805

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long cut_down_trees(vector<int> &trees, int height);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_trees = 0, required = 0;
    int low = 0, high = 0, mid = 0, max_value = 0, answer = 0;
    vector<int> trees;

    cin >> num_of_trees >> required;
    trees.reserve(num_of_trees);
    for (int i = 0, input = 0; i < num_of_trees; i++) {
        cin >> input;
        trees.push_back(input);
        if (input > max_value) {
            max_value = input;
        }
    }
    sort(trees.begin(), trees.end());

    high = max_value;
    while (low <= high) {
        mid = (high + low) / 2;
        if (cut_down_trees(trees, mid) >= required) {
            answer = max(answer, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}

long long cut_down_trees(vector<int> &trees, int height) {
    int low = 0, high = 0, mid = 0, index = 0;
    long long result = 0;

    high = trees.size() - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (trees[mid] > height) {
            index = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    for (int i = index; i < trees.size(); i++) {
        result += trees[i] - height;
    }

    return result;
}
