// BOJ-01918 / 후위 표기식
// devgeon, 2024.10.30, C++17
// https://www.acmicpc.net/problem/1918

#include <iostream>
#include <stack>

using namespace std;

inline bool is_first(char oper) {
    return oper == '*' || oper == '/';
}

inline bool is_second(char oper) {
    return oper == '+' || oper == '-';
}

inline bool is_same_level(char oper1, char oper2) {
    return is_first(oper1) && is_first(oper2) ||
           is_second(oper1) && is_second(oper2);
}

int main() {
    const int MAX_LEN = 100;
    char ch = 0;
    string expr = "";
    expr.reserve(MAX_LEN);
    stack<char> stack;

    while (cin >> ch) {
        if (isalpha(ch)) {
            expr.push_back(ch);
            continue;
        }
        if (stack.size()) {
            if (is_same_level(ch, stack.top())) {
                expr.push_back(stack.top());
                stack.pop();
            } else if (ch == ')' || (is_first(stack.top()) && is_second(ch))) {
                while (stack.size() && stack.top() != '(') {
                    expr.push_back(stack.top());
                    stack.pop();
                }
                if (ch == ')') {
                    stack.pop();
                    continue;
                }
            }
        }
        stack.push(ch);
    }
    while (stack.size()) {
        expr.push_back(stack.top());
        stack.pop();
    }

    for (const char ch : expr) {
        cout << ch;
    }
    cout << endl;

    return 0;
}
