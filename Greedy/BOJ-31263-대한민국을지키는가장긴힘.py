# BOJ-31263 / 대한민국을 지키는 가장 긴 힘
# devgeon, 2024.01.21, Python3
# https://www.acmicpc.net/problem/31263


def main():
    length = int(input())
    paper = input()
    i = length
    count = 0
    while i > 2:
        if paper[i - 3] != "0" and int(paper[i - 3 : i]) <= 641:
            i -= 3
        elif paper[i - 2] != "0":
            i -= 2
        else:
            i -= 1
        count += 1
    if i != 0:
        count += 1
    print(count)


if __name__ == "__main__":
    main()
