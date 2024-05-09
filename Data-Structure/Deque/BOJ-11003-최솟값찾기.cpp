// BOJ-11003 / 최솟값 찾기
// devgeon, 2024.05.09, C++17
// https://www.acmicpc.net/problem/11003

#include <deque>
#include <iostream>
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
};

bool operator<(const int num, const Item item) { return num < item.num; }
bool operator<=(const int num, const Item item) { return num <= item.num; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, dist = 0;
    cin >> num >> dist;

    vector<int> seq(num, 0);
    for (int &n : seq) {
        cin >> n;
    }
    deque<Item> deque;

    for (int i = 0; i < num; i++) {
        while (!deque.empty() && deque.front().index <= i - dist) {
            deque.pop_front();
        }
        while (!deque.empty() && deque.back().index <= i - dist) {
            deque.pop_back();
        }
        if (deque.empty() || seq[i] < deque.front()) {
            deque.emplace_front(seq[i], i);
        } else {
            while (!deque.empty() && seq[i] <= deque.back()) {
                deque.pop_back();
            }
            deque.emplace_back(seq[i], i);
        }
        cout << deque.front().num << ' ';
    }
    cout << endl;

    return 0;
}
