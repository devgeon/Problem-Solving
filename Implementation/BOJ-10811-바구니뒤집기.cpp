// BOJ-10811 / 바구니 뒤집기
// devgeon, 2024.04.21, C++17
// https://www.acmicpc.net/problem/10811

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b);

int main() {
    int num = 0, req = 0;
    cin >> num >> req;

    vector<int> baskets(num, 0);
    for (int i = 0; i < num; i++) {
        baskets[i] = i + 1;
    }

    for (int r = 0, i = 0, j = 0; r < req; r++) {
        cin >> i >> j;
        while (i < j) {
            swap(baskets[i - 1], baskets[j - 1]);
            i++;
            j--;
        }
    }

    for (int b : baskets) {
        cout << b << ' ';
    }
    cout << endl;

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
