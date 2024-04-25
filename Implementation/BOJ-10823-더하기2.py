# BOJ-10823 / 더하기 2
# devgeon, 2024.04.25, Python3
# https://www.acmicpc.net/problem/10823


import sys


def main():
    print(sum([int(x) for x in "".join(sys.stdin.readlines()).replace("\n", "").split(",")]))


if __name__ == "__main__":
    main()
