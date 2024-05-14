// BOJ-01012 / 유기농 배추
// devgeon, 2024.05.14, C++17
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>

using namespace std;

enum Status { EMPTY, CABBAGE, VISITED };

void depth_first_search(vector<vector<Status>> &farmland, int row, int col);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0, width = 0, height = 0, cabbages = 0, worms = 0;
    cin >> cases;

    while (cases--) {
        cin >> width >> height >> cabbages;
        vector<vector<Status>> farmland(height, vector<Status>(width, EMPTY));
        worms = 0;

        for (int row = 0, col = 0; cabbages--;) {
            cin >> col >> row;
            farmland[row][col] = CABBAGE;
        }

        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                if (farmland[row][col] != CABBAGE) {
                    continue;
                }
                depth_first_search(farmland, row, col);
                worms++;
            }
        }
        cout << worms << '\n';
    }

    return 0;
}

void depth_first_search(vector<vector<Status>> &farmland, int row, int col) {
    const vector<int> dr = {-1, 0, 0, 1};
    const vector<int> dc = {0, -1, 1, 0};

    if (farmland[row][col] != CABBAGE) {
        return;
    }
    farmland[row][col] = VISITED;
    for (int i = 0; i < dr.size(); i++) {
        if (row + dr[i] < 0 || row + dr[i] >= farmland.size() ||
            col + dc[i] < 0 || col + dc[i] >= farmland[0].size() ||
            farmland[row + dr[i]][col + dc[i]] != CABBAGE) {
            continue;
        }
        depth_first_search(farmland, row + dr[i], col + dc[i]);
    }
    return;
}
