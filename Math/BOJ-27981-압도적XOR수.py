# BOJ-27981 / 압도적 XOR 수
# devgeon, 2024.01.16, Python3
# https://www.acmicpc.net/problem/27981


def main():
    n, k = map(int, input().split())
    count = 1
    check = 4
    while check <= n:
        if check < (1 << (k + 1)):
            count += 1
        else:
            count += check >> k
        check <<= 1
    if (check >> k) >= check - n:
        count += (check >> k) - check + n + 1
    print(count)


if __name__ == "__main__":
    main()
