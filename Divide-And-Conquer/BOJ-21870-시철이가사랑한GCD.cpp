// BOJ-21870 / 시철이가 사랑한 GCD
// devgeon, 2024.04.11, C++17
// https://www.acmicpc.net/problem/21870

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);
int calc_gcd(int a, int b);
int calc_gcd_of_interval(vector<int> &list, int begin, int end);
int solve(vector<int> &list, int begin, int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<int> list(num, 0);
    for (int &n : list) {
        cin >> n;
    }

    cout << solve(list, 0, num) << endl;

    return 0;
}

void swap(int &a, int &b) {
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int calc_gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }

    if (b == 0) {
        return a;
    }

    return calc_gcd(b, a % b);
}

int calc_gcd_of_interval(vector<int> &list, int begin, int end) {
    int result = list[begin];

    for (int i = begin + 1; i < end; i++) {
        result = calc_gcd(list[i], result);
    }

    return result;
}

int solve(vector<int> &list, int begin, int end) {
    int left_sum = 0, right_sum = 0, mid = (begin + end) / 2;

    if (begin == end - 1) {
        return list[begin];
    }

    left_sum = solve(list, mid, end) + calc_gcd_of_interval(list, begin, mid);
    right_sum = solve(list, begin, mid) + calc_gcd_of_interval(list, mid, end);

    return max(left_sum, right_sum);
}
