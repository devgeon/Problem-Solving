// BOJ-07569 / 토마토
// devgeon, 2023.11.25, C++17
// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Position {
  public:
    int x = 0, y = 0, z = 0;
    Position(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};

int main() {
    int width = 0, length = 0, height = 0;
    int x = 0, y = 0, z = 0;
    int day = 0, unriped_tomato = 0;
    cin >> width >> length >> height;
    vector<vector<vector<int>>> box(
        length, vector<vector<int>>(width, vector<int>(height, -1)));
    queue<Position> queue;

    for (int z = 0; z < height; z++) {
        for (int y = 0; y < length; y++) {
            for (int x = 0; x < width; x++) {
                cin >> box[y][x][z];
                if (box[y][x][z] == 1) {
                    queue.push(Position(x, y, z));
                } else if (box[y][x][z] == 0) {
                    unriped_tomato++;
                }
            }
        }
    }
    queue.push(Position(-1, -1, -1));

    while (queue.size() > 1) {
        if (queue.front().x == -1) {
            day++;
            queue.push(queue.front());
            queue.pop();
            continue;
        }
        x = queue.front().x;
        y = queue.front().y;
        z = queue.front().z;
        queue.pop();

        if (0 <= x - 1 && box[y][x - 1][z] == 0) {
            box[y][x - 1][z] = 1;
            unriped_tomato--;
            queue.push(Position(x - 1, y, z));
        }
        if (x + 1 < width && box[y][x + 1][z] == 0) {
            box[y][x + 1][z] = 1;
            unriped_tomato--;
            queue.push(Position(x + 1, y, z));
        }
        if (0 <= y - 1 && box[y - 1][x][z] == 0) {
            box[y - 1][x][z] = 1;
            unriped_tomato--;
            queue.push(Position(x, y - 1, z));
        }
        if (y + 1 < length && box[y + 1][x][z] == 0) {
            box[y + 1][x][z] = 1;
            unriped_tomato--;
            queue.push(Position(x, y + 1, z));
        }
        if (0 <= z - 1 && box[y][x][z - 1] == 0) {
            box[y][x][z - 1] = 1;
            unriped_tomato--;
            queue.push(Position(x, y, z - 1));
        }
        if (z + 1 < height && box[y][x][z + 1] == 0) {
            box[y][x][z + 1] = 1;
            unriped_tomato--;
            queue.push(Position(x, y, z + 1));
        }
    }

    if (unriped_tomato > 0) {
        cout << -1;
    } else {
        cout << day;
    }

    return 0;
}
