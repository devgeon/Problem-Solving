# BOJ-27969 / I LOVE JavaScript
# devgeon, 2024.03.03, Python3
# https://www.acmicpc.net/problem/27969


def main():
    size = 0
    objects = input().split()

    for obj in objects:
        if obj == "[" or obj.isdigit():
            size += 8
        elif obj == "]":
            pass
        else:
            size += len(obj) + 12

    print(size)


if __name__ == "__main__":
    main()
