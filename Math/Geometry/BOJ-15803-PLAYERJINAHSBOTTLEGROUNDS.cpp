// BOJ-15803 / PLAYERJINAH’S BOTTLEGROUNDS
// devgeon, 2024.08.06, C++17
// https://www.acmicpc.net/problem/15803

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Coord {
  public:
    int x = 0, y = 0;

    friend istream &operator>>(istream &in, Coord &coord) {
        in >> coord.x >> coord.y;
        return in;
    }
};

class Gradient {
  public:
    int x_diff = 0, y_diff = 0;

    Gradient(int x_diff = 0, int y_diff = 0) {
        if (x_diff == 0 && y_diff != 0) {
            y_diff = 1;
        } else if (x_diff != 0 && y_diff == 0) {
            x_diff = 1;
        }
        this->x_diff = x_diff;
        this->y_diff = y_diff;
        reduction();
    }

    bool operator!=(const Gradient &gradient) {
        return x_diff != gradient.x_diff ||
               y_diff != gradient.y_diff;
    }

    void reduction() {
        int a = 0, b = 0, divisor = 0;
        a = abs(x_diff), b = abs(y_diff);
        divisor = _gcd(max(a, b), min(a, b));
        if (divisor == 0) {
            return;
        }
        x_diff /= divisor;
        y_diff /= divisor;
    }

  private:
    int _gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return _gcd(b, a % b);
    }
};

int main() {
    const int NUM = 3;
    int min_idx = 0;
    bool win = false;
    vector<Coord> players(NUM);
    Gradient base_gradient, gradient;

    for (int i = 0; i < NUM; i++) {
        cin >> players[i];
        if (players[i].x < players[min_idx].x) {
            min_idx = i;
        }
    }
    swap(players[0], players[min_idx]);

    base_gradient =
        Gradient(players[0].x - players[1].x,
                 players[0].y - players[1].y);
    for (int i = 2; i < NUM; i++) {
        gradient =
            Gradient(players[0].x - players[i].x,
                     players[0].y - players[i].y);
        if (gradient != base_gradient) {
            win = true;
            break;
        }
    }
    cout << (win ? "WINNER WINNER CHICKEN DINNER!"
                 : "WHERE IS MY CHICKEN?") << endl;

    return 0;
}
