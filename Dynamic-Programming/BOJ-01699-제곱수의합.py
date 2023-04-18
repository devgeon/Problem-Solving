# BOJ-01699 / 제곱수의 합
# devgeon, 2023.04.18, PyPy3
# https://www.acmicpc.net/problem/1699


def main():
    target = int(input())
    cache = [n for n in range(1, target + 1)]

    for i in range(4, target + 1):
        for j in range(2, i + 1):
            power = j * j
            if power < i:
                cache[i - 1] = min(cache[i - 1], cache[i - power - 1] + 1)
            elif power == i:
                cache[i - 1] = 1
            else:
                break

    print(cache[target - 1])


if __name__ == "__main__":
    main()
