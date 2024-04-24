# BOJ-10822 / 더하기
# devgeon, 2024.04.24, Python3
# https://www.acmicpc.net/problem/10822


import sys


def main():
    print(sum([int(x) for x in sys.stdin.readline().rstrip().split(",")]))


if __name__ == "__main__":
    main()
