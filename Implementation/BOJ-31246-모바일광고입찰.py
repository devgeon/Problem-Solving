# BOJ-31246 / 모바일 광고 입찰
# devgeon, 2024.01.14, Python3
# https://www.acmicpc.net/problem/31246

import sys

input = sys.stdin.readline


def main():
    n, k = [int(x) for x in input().split()]
    prices = [0] * n
    for i in range(n):
        a, b = [int(x) for x in input().split()]
        prices[i] = b - a
    prices.sort()

    if prices[k - 1] < 0:
        print(0)
    else:
        print(prices[k - 1])


if __name__ == "__main__":
    main()
