// BOJ-04796 / 캠핑
// devgeon, 2023.12.10, C++17
// https://www.acmicpc.net/problem/4796

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int length = 0, period = 0, vacation = 0;
    int case_count = 1, result = 0;

    while (true) {
        cin >> length >> period >> vacation;
        if (!length) {
            break;
        }
        result = vacation / period * length +
                 (vacation % period > length ? length : vacation % period);
        cout << "Case " << case_count << ": " << result << "\n";
        case_count++;
    }

    return 0;
}
