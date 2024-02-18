// BOJ-31409 / 착신 전환 소동
// devgeon, 2024.02.17, C++17
// https://www.acmicpc.net/problem/31409

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, count = 0;
    cin >> num;
    vector<int> forwarding(num, 0);

    for (int i = 0; i < num; i++) {
        cin >> forwarding[i];
        if (forwarding[i] == i + 1) {
            forwarding[i]++;
            count++;
        }
    }
    if (forwarding[num - 1] == num + 1) {
        forwarding[num - 1] = num - 1;
    }

    cout << count << "\n";
    for (int n : forwarding) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
