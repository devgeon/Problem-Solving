// BOJ-11651 / 좌표 정렬하기 2
// devgeon, 2024.10.19, C++17
// https://www.acmicpc.net/problem/11651

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Coord {
  public:
    int x = 0, y = 0;

    Coord(int x, int y) {
        this->x = x, this->y = y;
    }

    bool operator<(const Coord &coord) const {
        if (this->y < coord.y) {
            return true;
        }
        if (this->y == coord.y && this->x < coord.x) {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &out, const Coord &coord) {
        out << coord.x << ' ' << coord.y;
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin >> num;

    vector<Coord> coord_list;
    coord_list.reserve(num);

    for (int i = 0, x = 0, y = 0; i < num; i++) {
        cin >> x >> y;
        coord_list.emplace_back(x, y);
    }
    sort(coord_list.begin(), coord_list.end());

    for (const Coord &coord : coord_list) {
        cout << coord << '\n';
    }

    return 0;
}
