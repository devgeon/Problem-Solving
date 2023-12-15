# BOJ-04396 / 지뢰 찾기
# devgeon, 2023.11.24, Python3
# https://www.acmicpc.net/problem/4396


def main():
    n = int(input())
    mines = []
    opened = []
    board = [["." for _ in range(n)] for _ in range(n)]
    game_over = False

    # 주변 지뢰 합산 편의를 위해 패딩 추가
    mines.append([False for _ in range(n + 2)])
    for _ in range(n):
        mines.append([False] + [True if x == "*" else False for x in input()] + [False])
    mines.append([False for _ in range(n + 2)])
    for _ in range(n):
        opened.append([True if x == "x" else False for x in input()])

    for x in range(n):
        for y in range(n):
            if opened[x][y]:
                if mines[x + 1][y + 1]:
                    # 지뢰가 있으면서 열린 칸
                    board[x][y] = "*"
                    game_over = True
                else:
                    # 지뢰가 없으면서 열린 칸
                    board[x][y] = str(
                        sum(
                            # 패딩으로 기본 인덱스 + 1
                            mines[x][y : y + 3]
                            + mines[x + 1][y : y + 3]
                            + mines[x + 2][y : y + 3]
                        )
                    )
    for x in range(n):
        for y in range(n):
            if game_over and mines[x + 1][y + 1]:
                board[x][y] = "*"
            print(board[x][y], end="")
        print()


if __name__ == "__main__":
    main()
