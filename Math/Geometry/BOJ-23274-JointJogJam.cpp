// BOJ-23274 / Joint Jog Jam
// devgeon, 2024.07.11, C++17
// https://www.acmicpc.net/problem/23274

#include <cmath>
#include <iostream>

using namespace std;

class Pos {
  public:
    int x = 0, y = 0;

    Pos(int x = 0, int y = 0) {
        this->x = x, this->y = y;
    }

    double dist(Pos &pos) {
        return sqrt((this->x - pos.x) * (this->x - pos.x) +
                    (this->y - pos.y) * (this->y - pos.y));
    }
};

istream &operator>>(istream &in, Pos &pos) {
    in >> pos.x >> pos.y;
    return in;
}

int main() {
    Pos pos1, pos2;
    double distance = 0;

    for (int i = 0; i < 2; i++) {
        cin >> pos1 >> pos2;
        distance = max(distance, pos1.dist(pos2));
    }
    cout << fixed;
    cout.precision(6);
    cout << distance << endl;

    return 0;
}
