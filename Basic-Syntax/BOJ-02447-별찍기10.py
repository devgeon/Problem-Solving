# BOJ-02447 / 별 찍기 - 10
# devgeon, 2023.03.19, Python3
# https://www.acmicpc.net/problem/2447


def draw_pattern(buffer, scope):
    row, col, size = scope["row"], scope["col"], scope["size"]

    for r in range(size//3, size*2//3):
        for c in range(size//3, size*2//3):
            buffer[row+r][col+c] = False


def main():
    size = int(input())
    buffer = [[True for col in range(size)] for row in range(size)]

    pattern_size = size
    while pattern_size > 1:
        for row in range(0, size, pattern_size):
            for col in range(0, size, pattern_size):
                scope = {"row" : row, "col" : col, "size" : pattern_size}
                draw_pattern(buffer, scope)
        pattern_size //= 3
    
    for row in buffer:
        for col in row:
            if col:
                print("*", end="")
            else:
                print(" ", end="")
        print("")


if __name__ == "__main__":
    main()
