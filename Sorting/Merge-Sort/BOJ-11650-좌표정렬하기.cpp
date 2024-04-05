// BOJ-11650 / 좌표 정렬하기
// devgeon, 2024.04.05, C++17
// https://www.acmicpc.net/problem/11650

#include <iostream>
#include <vector>

using namespace std;

class Coord {
  public:
    int x = 0;
    int y = 0;

    bool operator==(const Coord &coord) const {
        return this->x == coord.x && this->y == coord.y;
    }
    bool operator<(const Coord &coord) const {
        return this->x < coord.x || (this->x == coord.x && this->y < coord.y);
    }
    bool operator>(const Coord &coord) const {
        return this->x > coord.x || (this->x == coord.x && this->y > coord.y);
    }
    bool operator<=(const Coord &coord) const {
        return *this < coord || *this == coord;
    }
    bool operator>=(const Coord &coord) const {
        return *this > coord || *this == coord;
    }
};

void merge_sort(vector<Coord> &coords, int begin, int end);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<Coord> coords(num, Coord());
    for (int i = 0; i < num; i++) {
        cin >> coords[i].x >> coords[i].y;
    }

    merge_sort(coords, 0, num);

    for (auto coord : coords) {
        cout << coord.x << ' ' << coord.y << '\n';
    }

    return 0;
}

void merge_sort(vector<Coord> &coords, int begin, int end) {
    int mid = (begin + end) / 2, left = begin, right = mid;
    vector<Coord> sorted;

    if (end - begin == 1) {
        return;
    }

    sorted.reserve(end - begin);
    merge_sort(coords, begin, mid);
    merge_sort(coords, mid, end);

    while (left < mid && right < end) {
        if (coords[left] < coords[right]) {
            sorted.push_back(coords[left++]);
        } else {
            sorted.push_back(coords[right++]);
        }
    }
    while (left < mid) {
        sorted.push_back(coords[left++]);
    }
    while (right < end) {
        sorted.push_back(coords[right++]);
    }

    for (int i = begin; i < end; i++) {
        coords[i] = sorted[i - begin];
    }
}
