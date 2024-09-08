// BOJ-06052 / Cow Pals
// devgeon, 2024.09.08, C++17
// https://www.acmicpc.net/problem/6052

#include <iostream>

using namespace std;

int get_pal_num(int num);

int main() {
    int num = 0, sum = 0;
    cin >> num;

    while (true) {
        sum = get_pal_num(num);
        if (sum != num && get_pal_num(sum) == num) {
            break;
        }
        num++;
    }
    cout << num << ' ' << sum << endl;

    return 0;
}

int get_pal_num(int num) {
    int sum = 1, i = 0;

    for (i = 2; i * i < num; i++) {
        if (num % i == 0) {
            sum += i + num / i;
        }
    }
    if (i * i == num) {
        sum += i;
    }

    return sum;
}
