# BOJ-17288 / 3개만!
# devgeon, 2024.01.17, Python3
# https://www.acmicpc.net/problem/17288


def main():
    s = [int(x) for x in input()]
    last = s[0]
    s = s[1:] + [-1]
    count = 1
    result = 0
    for c in s:
        if last + 1 == c:
            count += 1
        else:
            if count == 3:
                result += 1
            count = 1
        last = c
    print(result)


if __name__ == "__main__":
    main()
