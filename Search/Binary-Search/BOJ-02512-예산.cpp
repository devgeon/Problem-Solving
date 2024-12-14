// BOJ-02512 / 예산
// devgeon, 2024.12.14, C++17
// https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>

using namespace std;

int check(const vector<int> &requests, const int limit, const int total) {
    int sum = 0;
    for (const int req : requests) {
        sum += (req > limit ? limit : req);
    }
    return (sum > total ? 1 : (sum < total ? -1 : 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, total = 0, max = 0;
    int low = 0, mid = 0, high = 0, diff = 0;
    cin >> num;

    vector<int> requests(num, 0);
    for (int &req : requests) {
        cin >> req;
        max = (req > max ? req : max);
    }

    cin >> total;
    high = total;

    while (low < high) {
        mid = (low + high + 1) >> 1;
        diff = check(requests, mid, total);
        if (diff > 0) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    cout << (low == total ? max : low) << endl;

    return 0;
}
