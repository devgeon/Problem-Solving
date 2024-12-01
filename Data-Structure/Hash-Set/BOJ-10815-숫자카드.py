# BOJ-10815 / 숫자 카드
# devgeon, 2024.12.01, Python3
# https://www.acmicpc.net/problem/10815

import sys

readline = sys.stdin.readline
write = sys.stdout.write


def main():
    readline()
    cards = set()
    for card in map(int, readline().split()):
        cards.add(card)

    readline()
    for card in map(int, readline().split()):
        write(f"{str(int(card in cards))} ")


if __name__ == "__main__":
    main()
