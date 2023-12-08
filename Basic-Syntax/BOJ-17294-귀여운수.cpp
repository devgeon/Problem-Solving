// BOJ-17294 / 귀여운 수~ε٩(๑> ₃ <)۶з
// devgeon, 2023.12.08, C++17
// https://www.acmicpc.net/problem/17294

#include <iostream>

using namespace std;

int main() {
    char a = 0, b = 0;
    signed char d = 0;
    a = cin.get();
    b = cin.get();
    d = a - b;
    do {
        if (b < '0' || b > '9') {
            cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << endl;
            break;
        }
        if (a - b != d) {
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << endl;
            break;
        }
        a = b;
    } while (b = cin.get());

    return 0;
}
