# BOJ-02441 / 별 찍기 - 4
# devgeon, 2024.01.05, Python3
# https://www.acmicpc.net/problem/2441


def main():
    n = int(input())

    for i in range(n):
        print(" " * i, end="")
        print("*" * (n - i), end="")
        print()


if __name__ == "__main__":
    main()
