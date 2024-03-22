// BOJ-02751 / 수 정렬하기 2
// devgeon, 2024.03.22, C++17
// https://www.acmicpc.net/problem/2751

#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &list, int begin, int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<int> list(num, 0);
    for (int &n : list) {
        cin >> n;
    }

    merge_sort(list, 0, num);

    for (int n : list) {
        cout << n << "\n";
    }

    return 0;
}

void merge_sort(vector<int> &list, int begin, int end) {
    int mid = 0, left = 0, right = 0;
    vector<int> temp;

    if (end - begin <= 1) {
        return;
    }

    mid = (begin + end) / 2;
    merge_sort(list, begin, mid);
    merge_sort(list, mid, end);

    left = begin;
    right = mid;
    temp.reserve(end - begin + 1);

    while (left < mid && right < end) {
        if (list[left] <= list[right]) {
            temp.push_back(list[left]);
            left++;
        } else {
            temp.push_back(list[right]);
            right++;
        }
    }
    while (left < mid) {
        temp.push_back(list[left]);
        left++;
    }
    while (right < end) {
        temp.push_back(list[right]);
        right++;
    }

    for (int i = begin; i < end; i++) {
        list[i] = temp[i - begin];
    }
}
