// BOJ-28117 / prlong longf
// devgeon, 2024.03.06, C++17
// https://www.acmicpc.net/problem/28117

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int pos = 0, size = 0, count = 0, answer = 1;
    string code = "";
    vector<int> fibo(21, 1);
    for (int i = 2; i < fibo.size(); i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cin >> size >> code;

    while ((pos = code.find("long", pos)) != string::npos) {
        count = 0;
        while (code.substr(pos, 4) == "long") {
            count += 1;
            pos += 4;
            if (pos >= code.size()) {
                break;
            }
        }
        answer *= fibo[count];
    }

    cout << answer << endl;

    return 0;
}
