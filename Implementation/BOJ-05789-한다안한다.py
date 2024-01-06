# BOJ-05789 / 한다 안한다
# devgeon, 2024.01.06, Python3
# https://www.acmicpc.net/problem/5789

import sys

input = sys.stdin.readline


def main():
    num = int(input())

    while num:
        string = input().rstrip()
        index = len(string) // 2
        if string[index - 1] == string[index]:
            print("Do-it")
        else:
            print("Do-it-Not")
        num -= 1


if __name__ == "__main__":
    main()
