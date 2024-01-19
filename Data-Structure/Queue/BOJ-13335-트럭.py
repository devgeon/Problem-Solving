# BOJ-13335 / 트럭
# devgeon, 2024.01.19, Python3
# https://www.acmicpc.net/problem/13335


import sys
from collections import deque

input = sys.stdin.readline


def main():
    _, width, max_load = map(int, input().split())
    weights = deque(map(int, input().split()))
    time, cur_load = 0, 0
    bridge = deque([0] * width)

    while bridge:
        cur_load -= bridge.popleft()
        if weights:
            if cur_load + weights[0] <= max_load:
                bridge.append(weights[0])
                cur_load += weights.popleft()
            else:
                bridge.append(0)
        time += 1

    print(time)


if __name__ == "__main__":
    main()
