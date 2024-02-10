// BOJ-18870 / 좌표 압축
// devgeon, 2024.02.09, C++17
// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <vector>

using namespace std;

vector<int> argsort(const vector<int> &coords);
void _mergesort(const vector<int> &coords, vector<int> &index, int begin,
                int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, input = 0;
    cin >> num;
    vector<int> coords;
    coords.reserve(num);
    for (int i = 0; i < num; i++) {
        cin >> input;
        coords.push_back(input);
    }

    vector<int> sorted = argsort(coords);
    for (int i = 0, x_prime = 0, increased = 1; i < num; i++, increased = 1) {
        if (i < num - 1 && coords[sorted[i]] == coords[sorted[i + 1]]) {
            increased = 0;
        }
        coords[sorted[i]] = x_prime;
        x_prime += increased;
    }

    for (int c : coords) {
        cout << c << " ";
    }

    return 0;
}

vector<int> argsort(const vector<int> &coords) {
    int size = coords.size();
    vector<int> sorted;
    sorted.reserve(size);
    for (int i = 0; i < size; i++) {
        sorted.push_back(i);
    }

    _mergesort(coords, sorted, 0, size);

    return sorted;
}

void _mergesort(const vector<int> &coords, vector<int> &index, int begin,
                int end) {
    if (end - begin == 1) {
        return;
    }

    int mid = (begin + end) / 2, left = begin, right = mid;
    vector<int> answer;
    answer.reserve(end - begin);

    _mergesort(coords, index, begin, mid);
    _mergesort(coords, index, mid, end);

    while (left < mid && right < end) {
        if (coords[index[left]] < coords[index[right]]) {
            answer.push_back(index[left]);
            left++;
        } else {
            answer.push_back(index[right]);
            right++;
        }
    }
    while (left < mid) {
        answer.push_back(index[left]);
        left++;
    }
    while (right < end) {
        answer.push_back(index[right]);
        right++;
    }

    for (int i = begin; i < end; i++) {
        index[i] = answer[i - begin];
    }
}
