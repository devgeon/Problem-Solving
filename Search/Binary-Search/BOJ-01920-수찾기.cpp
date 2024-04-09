// BOJ-01920 / 수 찾기
// devgeon, 2024.04.09, C++17
// https://www.acmicpc.net/problem/1920

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &array, int num);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, query = 0;
    cin >> num;

    vector<int> array(num, 0);
    for (int &n : array) {
        cin >> n;
    }
    sort(array.begin(), array.end());

    cin >> num;
    while (num--) {
        cin >> query;
        cout << (find(array, query) < 0 ? 0 : 1) << '\n';
    }

    return 0;
}

int find(vector<int> &array, int num) {
    int left = 0, right = array.size() - 1, mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (array[mid] < num) {
            left = mid + 1;
        } else if (num < array[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
