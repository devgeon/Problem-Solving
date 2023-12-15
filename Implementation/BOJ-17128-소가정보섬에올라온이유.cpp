// BOJ-17128 / 소가 정보섬에 올라온 이유
// devgeon, 2023.11.23, C++17
// https://www.acmicpc.net/problem/17128

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int result = 0;
    int total_cows = 0, total_tricks = 0;
    cin >> total_cows >> total_tricks;
    vector<int> cows(total_cows, 0);
    for (int i = 0; i < total_cows; i++) {
        cin >> cows[i];
    }
    vector<int> tricks(total_tricks, 0);
    for (int i = 0; i < total_tricks; i++) {
        cin >> tricks[i];
        tricks[i]--;
    }

    for (int i = 0; i < total_cows; i++) {
        result += cows[i] * cows[(i + 1) % total_cows] *
                  cows[(i + 2) % total_cows] * cows[(i + 3) % total_cows];
    }
    for (int i = 0; i < total_tricks; i++) {
        cows[tricks[i]] *= -1;
        for (int j = tricks[i]; j < tricks[i] + 4; j++) {
            result += 2 * (cows[(j - 3 + total_cows) % total_cows] *
                           cows[(j - 2 + total_cows) % total_cows] *
                           cows[(j - 1 + total_cows) % total_cows] *
                           cows[(j + total_cows) % total_cows]);
        }
        cout << result << "\n";
    }

    return 0;
}
