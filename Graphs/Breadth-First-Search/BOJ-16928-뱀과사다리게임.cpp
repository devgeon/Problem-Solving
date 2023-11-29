// BOJ-16928 / 뱀과 사다리 게임
// devgeon, 2023.11.29, C++17
// https://www.acmicpc.net/problem/16928

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int count_dice = 1;
    const int VISITED = 100;
    const int ROLL_DICE = -1;
    vector<int> board(100, -1);
    int location = 0, from = 0, to = 0;
    int total_ladder = 0, total_snake = 0;
    cin >> total_ladder >> total_snake;
    for (int i = 0; i < total_ladder + total_snake; i++) {
        cin >> from >> to;
        board[from - 1] = to - 1;
    }
    queue<int> queue;
    queue.push(0);
    queue.push(ROLL_DICE);
    bool moved = false;
    while (!queue.empty()) {
        moved = false;
        if (queue.front() == ROLL_DICE) {
            count_dice++;
            queue.push(ROLL_DICE);
            queue.pop();
        }
        for (int i = 6; i > 0; i--) {
            location = queue.front() + i;
            // 마지막 칸 도착
            if (location == 99) {
                cout << count_dice << endl;
                return 0;
            } else if (location > 99) {
                continue;
            }
            // 처음 방문하는 칸
            if (board[location] == -1) {
                if (!moved) {
                    queue.push(location);
                    moved = true;
                }
            } else {
                // 방문했던 칸 재방문
                if (board[location] == VISITED) {
                    continue;
                }
                // 사다리 혹은 뱀 출발칸이면서
                // 도착칸도 처음 방문하는 경우
                else if (board[board[location]] != VISITED) {
                    queue.push(board[location]);
                    board[board[location]] = VISITED;
                }
            }
            board[location] = VISITED;
        }
        queue.pop();
    }

    return 0;
}
