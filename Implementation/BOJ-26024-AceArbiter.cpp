// BOJ-26024 / Ace Arbiter
// devgeon, 2024.07.21, C++17
// https://www.acmicpc.net/problem/26024

#include <iostream>

using namespace std;

int main() {
    bool error = false;
    int num = 0, alice = 0, bob = 0, prev_alice = 0, prev_bob = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> alice >> bob;
        bob *= -1;
        if ((alice + bob + 1) / 2 % 2) {
            swap(alice, bob);
        }
        if (alice > 11 || bob > 11 || alice < prev_alice || bob < prev_bob ||
            alice == 11 && bob == 11 || prev_alice == 11 && bob > prev_bob ||
            prev_bob == 11 && alice > prev_alice) {
            cout << "error " << i + 1 << endl;
            error = true;
            break;
        }
        prev_alice = alice, prev_bob = bob;
    }
    if (!error) {
        cout << "ok" << endl;
    }

    return 0;
}
