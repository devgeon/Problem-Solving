# BOJ-09012 / 괄호
# devgeon, 2024.03.27, Python3
# https://www.acmicpc.net/problem/9012


import sys


def readline():
    return sys.stdin.readline().rstrip()


def main():
    for _ in range(int(readline())):
        stack_length = 0
        for bracket in readline():
            if bracket == "(":
                stack_length += 1
                continue
            stack_length -= 1
            if stack_length < 0:
                break
        is_vps = stack_length == 0
        print("YES" if is_vps else "NO")


if __name__ == "__main__":
    main()
