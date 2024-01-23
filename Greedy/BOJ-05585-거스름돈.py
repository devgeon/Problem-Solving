# BOJ-05585 / 거스름돈
# devgeon, 2024.01.23, Python3
# https://www.acmicpc.net/problem/5585


def main():
    money = 1000 - int(input())
    count = 0
    for change in [500, 100, 50, 10, 5, 1]:
        if money >= change:
            count += money // change
            money %= change
    print(count)


if __name__ == "__main__":
    main()
