// BOJ-10773 / 제로
// devgeon, 2024.10.13, C++17
// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>

using namespace std;

class SumStack : stack<int> {
  private:
    int sum = 0;

  public:
    void push(const int x) {
        sum += x;
        stack<int>::push(x);
    }

    void pop() {
        sum -= stack<int>::top();
        stack<int>::pop();
    }

    int get_sum() {
        return this->sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 0, num = 0;
    SumStack stack;
    cin >> count;

    while (count--) {
        cin >> num;
        if (num == 0)
            stack.pop();
        else
            stack.push(num);
    }
    cout << stack.get_sum() << endl;

    return 0;
}
