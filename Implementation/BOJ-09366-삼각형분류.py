# BOJ-09366 / 삼각형 분류
# devgeon, 2024.05.02, Python3
# https://www.acmicpc.net/problem/9366


import sys


def readline():
    return sys.stdin.readline().rstrip()


def main():
    num = int(readline())
    messages = ["invalid!", "equilateral", "isosceles", "scalene"]

    for case in range(1, num + 1):
        lines = sorted([int(x) for x in readline().split()])
        if lines[0] + lines[1] <= lines[2]:
            lines = []
        print(f"Case #{case}: {messages[len(set(lines))]}")


if __name__ == "__main__":
    main()
