// BOJ-11003 / 최솟값 찾기
// devgeon, 2024.05.09, C++17
// https://www.acmicpc.net/problem/11003

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Item {
  public:
    int num;
    int index;

    Item(int num, int index) {
        this->num = num;
        this->index = index;
    }

    bool operator>(const Item &item) const { return this->num > item.num; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, dist = 0;
    cin >> num >> dist;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    priority_queue<Item, vector<Item>, greater<Item>> pQueue;

    for (int i = 0; i < num; i++) {
        pQueue.emplace(seq[i], i);
        while (pQueue.top().index <= i - dist) {
            pQueue.pop();
        }
        cout << pQueue.top().num << ' ';
    }
    cout << endl;

    return 0;
}
