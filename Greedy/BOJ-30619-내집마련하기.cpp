// BOJ-30619 / 내 집 마련하기
// devgeon, 2024.08.10, C++17
// https://www.acmicpc.net/problem/30619

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_of_houses = 0, num_of_queries = 0;
    int left = 0, right = 0, next_resident = 0;
    cin >> num_of_houses;

    vector<int> houses(num_of_houses, 0);
    for (int &resident : houses) {
        cin >> resident;
    }

    cin >> num_of_queries;
    while (num_of_queries--) {
        cin >> left >> right;
        next_resident = left;
        for (int resident : houses) {
            if (resident < left || resident > right) {
                cout << resident << ' ';
                continue;
            }
            cout << next_resident++ << ' ';
        }
        cout << '\n';
    }

    return 0;
}
