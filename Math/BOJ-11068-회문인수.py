# BOJ-11068 / 회문인 수
# devgeon, 2024.04.27, Python3
# https://www.acmicpc.net/problem/11068


import sys

readline = sys.stdin.readline
write = sys.stdout.write


def change_base(num: int, base: int) -> list[int]:
    result: list[int] = []
    while num > 0:
        result.append(num % base)
        num //= base
    return result[::-1]


def palindrome(input_: list[int]) -> bool:
    length: int = len(input_)
    for i in range(length // 2):
        if input_[i] != input_[-i - 1]:
            return False
    return True


def main():
    cases = int(readline())
    for _ in range(cases):
        num: int = int(readline())
        answer: bool = False
        for base in range(2, 65):
            if palindrome(change_base(num, base)):
                answer = True
                break
        write("1\n" if answer else "0\n")


if __name__ == "__main__":
    main()
