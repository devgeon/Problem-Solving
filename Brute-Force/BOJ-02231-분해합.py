# BOJ-02231 / 분해합
# devgeon, 2024.02.03, Python3
# https://www.acmicpc.net/problem/2231


def main():
    num = int(input())
    for n in range(max(1, num - 9 * len(str(num))), num):
        if n + sum(map(int, str(n))) == num:
            print(n)
            return
    print(0)
    return


if __name__ == "__main__":
    main()
