# BOJ-17492 / 바둑알 점프
# devgeon, 2024.01.12, Python3
# https://www.acmicpc.net/problem/17492


import sys
from copy import deepcopy

input = sys.stdin.readline

BLANK = 0
WALL = 1
STONE = 2


def play(board):
    result = False
    count = 0
    steps = [(-2, 0), (-2, 2), (0, 2), (2, 2), (2, 0), (2, -2), (0, -2), (-2, -2)]

    for row, line in enumerate(board):
        for col, item in enumerate(line):
            if item != STONE:
                continue
            count += 1

            for step in steps:
                try:
                    if (
                        board[row + step[0] // 2][col + step[1] // 2] == STONE
                        and board[row + step[0]][col + step[1]] == BLANK
                    ):
                        new_board = deepcopy(board)
                        new_board[row][col] = BLANK
                        new_board[row + step[0] // 2][col + step[1] // 2] = BLANK
                        new_board[row + step[0]][col + step[1]] = STONE
                        result = result or play(new_board)
                except IndexError:
                    continue

                if result:
                    return result

    result = count == 1
    return result


def main():
    n = int(input())
    board = [[int(x) for x in input().split()] for _ in range(n)]

    if play(board):
        print("Possible")
    else:
        print("Impossible")


if __name__ == "__main__":
    main()
