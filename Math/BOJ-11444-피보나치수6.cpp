// BOJ-11444 / 피보나치 수 6
// devgeon, 2024.11.06, C++17
// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <vector>

using namespace std;

class Fibo {
  public:
    const static int divisor = 1'000'000'007;
    long long num = 1LL;
    int next = 1, curr = 1, prev = 0;

    const Fibo &operator*=(const Fibo &fibo) {
        int next = 0, curr = 0, prev = 0;
        next = (int)(((long long)this->next * fibo.next +
                      (long long)this->curr * fibo.curr) % divisor);
        curr = (int)(((long long)this->next * fibo.curr +
                      (long long)this->curr * fibo.prev) % divisor);
        prev = (int)(((long long)this->curr * fibo.curr +
                      (long long)this->prev * fibo.prev) % divisor);
        this->next = next, this->curr = curr, this->prev = prev;
        this->num += fibo.num;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Fibo &fibo) {
        out << fibo.curr;
        return out;
    }
};

void solve(const Fibo &base, long long num, Fibo &result) {
    if (num < 2LL) {
        return;
    }
    solve(base, num / 2LL, result);
    result *= result;
    if (num & 1LL) {
        result *= base;
    }
}

int main() {
    long long num = 0LL;
    cin >> num;

    const Fibo base;
    Fibo result;

    solve(base, num, result);
    cout << result << endl;

    return 0;
}
