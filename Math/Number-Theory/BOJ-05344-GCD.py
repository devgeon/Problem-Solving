# BOJ-05344 / GCD
# devgeon, 2025.04.30, Python3
# https://www.acmicpc.net/problem/5344


import sys

readline = sys.stdin.readline
write = sys.stdout.write


def gcd(a: int, b: int) -> int:
    if b > a:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


def main():
    cases = int(readline())
    for _ in range(cases):
        a, b = [int(x) for x in readline().split()]
        write(f"{gcd(a, b)}\n")


if __name__ == "__main__":
    main()
