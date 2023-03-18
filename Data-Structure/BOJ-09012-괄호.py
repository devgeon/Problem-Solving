# BOJ-09012 / 괄호
# devgeon, 2023.03.18, Python3
# https://www.acmicpc.net/problem/9012

import sys

def readline():
    return sys.stdin.readline().rstrip()


def main():
    for _ in range(int(readline())):
        is_vps = True
        stack_length = 0

        for bracket in readline():
            if bracket == "(":
                stack_length += 1
            elif stack_length == 0:
                is_vps = False
                break
            else:
                stack_length -= 1

        if stack_length != 0:
            is_vps = False

        if is_vps:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()
