// BOJ-05555 / 반지
// devgeon, 2024.07.31, C++17
// https://www.acmicpc.net/problem/5555

#include <iostream>

using namespace std;

int main() {
    const int LEN = 10;
    int num = 0, count = 0;
    string keyword = "", ring_string = "";
    cin >> keyword >> num;

    while (num--) {
        cin >> ring_string;
        for (int i = 0, check_index = 0; i < LEN + keyword.size() - 1;) {
            if (ring_string[i % LEN] != keyword[check_index]) {
                i = i - check_index + 1;
                check_index = 0;
                continue;
            }
            check_index++;
            if (check_index < keyword.size()) {
                i++;
                continue;
            }
            count++;
            break;
        }
    }
    cout << count << endl;

    return 0;
}
