// BOJ-01351 / 무한 수열
// devgeon, 2024.03.24, C++17
// https://www.acmicpc.net/problem/1351

#include <iostream>
#include <unordered_map>

using namespace std;

long long solve(long long num, int p, int q,
                unordered_map<long long, long long> &cache);

int main() {
    long long num = 0;
    int p = 0, q = 0;
    unordered_map<long long, long long> cache;

    cin >> num >> p >> q;

    cout << solve(num, p, q, cache) << endl;

    return 0;
}

long long solve(long long num, int p, int q,
                unordered_map<long long, long long> &cache) {
    if (num == 0LL) {
        return 1;
    }
    if (cache.find(num) != cache.end()) {
        return (*cache.find(num)).second;
    }

    cache[num] = solve(num / p, p, q, cache) + solve(num / q, p, q, cache);

    return cache[num];
}
