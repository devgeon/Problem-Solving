// BOJ-28116 / 선택 정렬의 이동 거리
// devgeon, 2024.03.07, C++17
// https://www.acmicpc.net/problem/28116

#include <iostream>
#include <vector>

using namespace std;

void swap(int &num1, int &num2);

void solve(vector<int> &sequence, vector<int> &index, vector<int> &distance);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<int> index(num, 0);
    vector<int> sequence(num, 0);
    vector<int> distance(num, 0);
    for (int i = 0; i < num; i++) {
        cin >> sequence[i];
        index[sequence[i] - 1] = i;
    }

    solve(sequence, index, distance);

    for (int d : distance) {
        cout << d << ' ';
    }
    cout << endl;

    return 0;
}

void swap(int &num1, int &num2) {
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void solve(vector<int> &sequence, vector<int> &index, vector<int> &distance) {
    for (int sorted = 0, min = 0; sorted < sequence.size(); sorted++) {
        min = index[sorted];

        swap(index[sequence[sorted] - 1], index[sequence[min] - 1]);
        swap(sequence[sorted], sequence[min]);
        swap(distance[sorted], distance[min]);

        distance[sorted] += min - sorted;
        distance[min] += min - sorted;
    }
}
