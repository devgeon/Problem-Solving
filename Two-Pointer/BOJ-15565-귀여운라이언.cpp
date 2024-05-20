// BOJ-15565 / 귀여운 라이언
// devgeon, 2024.05.20, C++17
// https://www.acmicpc.net/problem/15565

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename Type>
class TotalSumQueue : public queue<Type> {
  private:
    Type total_sum = Type();

  public:
    const Type get_total_sum() {
        return this->total_sum;
    }

    void push(const Type item) {
        this->total_sum += item;
        queue<Type>::push(item);
    }

    void pop() {
        this->total_sum -= this->front();
        queue<Type>::pop();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1'000'001;
    int num = 0, required = 0, answer = MAX;
    TotalSumQueue<int> sum_queue;
    cin >> num >> required;

    for (int i = 0, input = 0, count = 0, is_first = 1; i < num; i++) {
        cin >> input;
        if (input == 2) {
            count++;
            continue;
        }
        if (is_first) {
            is_first--;
            continue;
        }
        sum_queue.push(count);
        if (sum_queue.size() == required - 1) {
            answer = min(sum_queue.get_total_sum() + required, answer);
            sum_queue.pop();
        }
        count = 0;
    }
    cout << (answer == MAX ? -1 : answer) << endl;

    return 0;
}
