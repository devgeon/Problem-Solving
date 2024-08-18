// BOJ-12033 / 김인천씨의 식료품가게 (Small)
// devgeon, 2024.08.18, C++17
// https://www.acmicpc.net/problem/12033

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0, count = 0, price = 0;
    queue<int> queue;
    cin >> cases;

    for (int c = 1; c <= cases; c++) {
        cin >> count;
        cout << "Case #" << c << ": ";
        for (int i = 0; i < count * 2; i++) {
            cin >> price;
            if (queue.empty() || queue.front() / 3 * 4 != price) {
                queue.push(price);
                continue;
            }
            cout << queue.front() << ' ';
            queue.pop();
        }
        cout << '\n';
    }

    return 0;
}
