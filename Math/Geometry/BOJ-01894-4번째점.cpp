// BOJ-01894 / 4번째 점
// devgeon, 2024.04.10, C++17
// https://www.acmicpc.net/problem/1894

#include <iostream>
#include <vector>

using namespace std;

class Point {
  public:
    double x;
    double y;

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    void clear() {
        this->x = 0;
        this->y = 0;
    }

    Point &operator+=(Point &point) {
        this->x += point.x;
        this->y += point.y;
        return *this;
    }

    Point &operator-=(Point &point) {
        this->x -= point.x;
        this->y -= point.y;
        return *this;
    }

    bool operator==(Point &point) {
        return this->x == point.x && this->y == point.y;
    }

    friend istream &operator>>(istream &in, Point &point) {
        in >> point.x >> point.y;
        return in;
    }

    friend ostream &operator<<(ostream &out, Point &point) {
        out << point.x << ' ' << point.y;
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int common = 0;
    bool skip = false;
    double x = 0, y = 0;
    Point input = Point(0, 0), answer = Point(0, 0);
    vector<Point> points;

    cout << fixed;
    cout.precision(3);

    while (true) {
        answer.clear();
        points.clear();

        for (int p = 0; p < 4; p++) {
            cin >> input;
            skip = false;
            for (int i = 0; i < points.size(); i++) {
                if (points[i].x == input.x && points[i].y == input.y) {
                    common = i;
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                points.push_back(input);
            }
        }

        if (cin.eof()) {
            break;
        }

        for (int i = 0; i < points.size(); i++) {
            if (i == common) {
                answer -= points[i];
                continue;
            }
            answer += points[i];
        }

        cout << answer << '\n';
    }

    return 0;
}
