# BOJ-31247 / 2024는 무엇이 특별할까?
# devgeon, 2024.01.15, Python3
# https://www.acmicpc.net/problem/31247


import sys

input = sys.stdin.readline


def main():
    t = int(input())
    for _ in range(t):
        n, k = [int(x) for x in input().split()]
        divisor = 1
        for _ in range(k):
            divisor <<= 1
            if divisor > n:
                break
        print((n + divisor) // (divisor << 1))


if __name__ == "__main__":
    main()
