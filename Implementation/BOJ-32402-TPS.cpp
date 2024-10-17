// BOJ-32402 / TPS
// devgeon, 2024.10.17, C++17
// https://www.acmicpc.net/problem/32402

#include <iostream>
#include <vector>

using namespace std;

class Pos {
  public:
    int x = 0, y = 0;
    Pos(int x, int y) { this->x = x, this->y = y; }
};

int main() {
    int num = 0, idx = 0, dir = 0; // direction: counter clockwise
    char cmd = 0;
    bool mouse = false;
    Pos player(0, 0), camera(0, -1);
    const vector<int> DX = {0, -1, 0, 1}, DY = {1, 0, -1, 0}; // w, a, s, d

    cin >> num;
    while (num--) {
        do {
            cin >> cmd;
        } while (cmd == 'M');

        switch (cmd) {
        case 'W':
            idx = dir;
            break;
        case 'A':
            idx = dir + 1;
            break;
        case 'S':
            idx = dir + 2;
            break;
        case 'D':
            idx = dir + 3;
            break;
        case 'R':
            dir--;
            if (dir < 0) {
                dir += 4;
            }
            mouse = true;
            break;
        case 'L':
            dir++;
            dir %= 4;
            mouse = true;
            break;
        default:
            break;
        }

        if (mouse) {
            mouse = false;
            camera.x = player.x - DX[dir];
            camera.y = player.y - DY[dir];
        } else {
            idx %= 4;
            player.x += DX[idx], player.y += DY[idx];
            camera.x += DX[idx], camera.y += DY[idx];
        }

        cout << player.x << ' ' << player.y << ' ';
        cout << camera.x << ' ' << camera.y << '\n';
    }

    return 0;
}
