// BOJ-12841 / 정보대 등산
// devgeon, 2024.10.06, C++17
// https://www.acmicpc.net/problem/12841

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    long long distance = 0L;
    long long min_crosswalk = 0L, min_distance = 100'000L * 100'000L + 1L;
    cin >> num;

    vector<int> crosswalk(num, 0);
    vector<long long> left_road(num, 0);
    vector<long long> right_road(num, 0);
    for (int i = 0; i < num; i++) {
        cin >> crosswalk[i];
    }
    for (int i = 1; i < num; i++) {
        cin >> left_road[i];
        left_road[i] += left_road[i - 1];
    }
    for (int i = 1; i < num; i++) {
        cin >> right_road[i];
        right_road[i] += right_road[i - 1];
    }

    for (int i = 0; i < num; i++) {
        distance = left_road[i] - left_road[0] + crosswalk[i] +
                   right_road[num - 1] - right_road[i];
        if (distance < min_distance) {
            min_distance = distance;
            min_crosswalk = i + 1;
        }
    }
    cout << min_crosswalk << ' ' << min_distance << endl;

    return 0;
}
