# BOJ-02628 / 종이자르기
# devgeon, 2024.05.01, Python3
# https://www.acmicpc.net/problem/2628


import sys

readline = sys.stdin.readline
write = sys.stdout.write


def max_diff(seq: list[int]) -> int:
    result = 0
    for i in range(len(seq) - 1):
        result = max(result, seq[i + 1] - seq[i])
    return result


def main():
    col_size, row_size = map(int, readline().split())
    num = int(readline())
    lines = [[0, row_size], [0, col_size]]
    for _ in range(num):
        direction, index = map(int, readline().split())
        lines[direction].append(index)
    lines[0].sort()
    lines[1].sort()
    answer = max_diff(lines[0]) * max_diff(lines[1])
    write(f"{answer}\n")


if __name__ == "__main__":
    main()
