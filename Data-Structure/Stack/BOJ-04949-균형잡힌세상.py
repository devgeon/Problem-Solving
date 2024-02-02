# BOJ-04949 / 균형잡힌 세상
# devgeon, 2024.02.02, Python3
# https://www.acmicpc.net/problem/4949


import sys

input = lambda: sys.stdin.readline().rstrip()

OPEN = "(["
CLOSE = ")]"


def main():
    while True:
        string = input()
        if string == ".":
            break
        stack = []
        result = True
        for c in string:
            if c in OPEN:
                stack.append(c)
            elif c in CLOSE and (not stack or stack.pop() != OPEN[CLOSE.find(c)]):
                result = False
        result = not stack and result
        print("yes" if result else "no")


if __name__ == "__main__":
    main()
