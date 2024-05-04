// BOJ-12852 / 1로 만들기 2
// devgeon, 2024.05.04, C++17
// https://www.acmicpc.net/problem/12852

#include <iostream>
#include <vector>

using namespace std;

class CacheItem {
  public:
    int count = 0;
    int result = 1;
};

int main() {
    const int MAX = 1'000'000;

    int num = 0;
    cin >> num;

    vector<CacheItem> cache(num, CacheItem{MAX, 1});
    cache[0].count = 0;

    for (int i = 2; i <= num; i++) {
        for (int j = 3; j > 1; j--) {
            if (i % j == 0 && cache[i / j - 1].count + 1 < cache[i - 1].count) {
                cache[i - 1].count = cache[i / j - 1].count + 1;
                cache[i - 1].result = i / j;
            }
        }
        if (cache[i - 2].count + 1 < cache[i - 1].count) {
            cache[i - 1].count = cache[i - 2].count + 1;
            cache[i - 1].result = i - 1;
        }
    }

    cout << cache[num - 1].count << '\n' << num;
    while (num > 1) {
        cout << ' ' << cache[num - 1].result;
        num = cache[num - 1].result;
    }
    cout << endl;

    return 0;
}
