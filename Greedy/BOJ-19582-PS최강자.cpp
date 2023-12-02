// BOJ-19582 / 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여
// devgeon, 2023.12.02, C++17
// https://www.acmicpc.net/problem/19582

#include <iostream>

using namespace std;

int main() {
    int num = 0;
    int max_prize = 0;
    long long total_prize = 0;
    int limit = 0, prize = 0, missed = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> limit >> prize;
        if (total_prize <= limit) {
            total_prize += prize;
            if (max_prize < prize) {
                max_prize = prize;
            }
        } else if (missed == 0) {
            if (max_prize > prize && total_prize - max_prize <= limit) {
                // 이전 대회 중 상금이 더 큰 대회가 있고
                // 해당 대회 포기 시 이번 대회 참여 가능
                total_prize -= max_prize;
                total_prize += prize;
            }
            // 이전 대회 중 하나를 포기해도
            // 이번 대회에 참여가 불가하거나
            // 이번 대회 상금이 더 큰 경우
            missed++;

        } else {
            missed++;
            break;
        }
    }

    if (missed < 2) {
        cout << "Kkeo-eok" << endl;
    } else {
        cout << "Zzz" << endl;
    }

    return 0;
}
