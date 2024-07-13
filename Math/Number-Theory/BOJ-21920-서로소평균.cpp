// BOJ-21920 / 서로소 평균
// devgeon, 2024.07.13, C++17
// https://www.acmicpc.net/problem/21920

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, len = 0, count = 0;
    long long total = 0;
    cin >> len;

    vector<int> seq(len, 0);
    for (int &n : seq) {
        cin >> n;
    }

    vector<int> prime_factors;
    cin >> num;
    for (int i = 2; i * i <= num; i++) {
        if (num % i) {
            continue;
        }
        prime_factors.push_back(i);
        while (num % i == 0) {
            num /= i;
        }
    }
    if (num != 1) {
        prime_factors.push_back(num);
    }

    for (int n : seq) {
        total += n;
        count++;
        for (int p : prime_factors) {
            if (n % p == 0) {
                total -= n;
                count--;
                break;
            }
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << (double)total / count << endl;

    return 0;
}
