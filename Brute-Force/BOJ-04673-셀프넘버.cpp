// BOJ-04673 / 셀프 넘버
// devgeon, 2025.04.22, C++17
// https://www.acmicpc.net/problem/4673

#include <bitset>
#include <iostream>

#define MAX_NUM 10000

using namespace std;

int sum_digits(int num) {
    int result = 0;
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bitset<MAX_NUM + 1> found;

    for (int i = 1; i <= MAX_NUM; i++) {
        if (found[i]) {
            continue;
        }
        cout << i << '\n';

        int num = i + sum_digits(i);
        while (num <= MAX_NUM) {
            found[num] = true;
            num += sum_digits(num);
        }
    }

    return 0;
}
