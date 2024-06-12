# BOJ-18766 / 카드 바꿔치기
# devgeon, 2024.06.12, Python3
# https://www.acmicpc.net/problem/18766


import sys

input = sys.stdin.readline


def main():
    test = int(input())

    for _ in range(test):
        input()
        deck = {}
        is_cheater = False

        for card in input().split():
            deck[card] = deck.setdefault(card, 0) + 1
        for card in input().split():
            if card not in deck or deck[card] == 0:
                is_cheater = True
                continue
            deck[card] -= 1

        if not is_cheater:
            print("NOT ", end="")
        print("CHEATER")


if __name__ == "__main__":
    main()
