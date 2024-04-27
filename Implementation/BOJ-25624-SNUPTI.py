# BOJ-25624 / SNUPTI
# devgeon, 2024.04.27, Python3
# https://www.acmicpc.net/problem/25624


import sys


def readline():
    return sys.stdin.readline().rstrip()


def main():
    num, lines = [int(x) for x in readline().split()]
    res_types = [set() for _ in range(num)]  # result types

    input_set = set()
    for _ in range(lines):
        string = readline()
        if string in input_set:
            print("NO")
            return
        input_set.add(string)
        for i, c in enumerate(string):
            res_types[i].add(c)

    sum_of_set = set()
    sum_of_size = 0
    mul_of_size = 1

    for _, set_ in enumerate(res_types):
        sum_of_set |= set_
        sum_of_size += len(set_)
        mul_of_size *= len(set_)

    if sum_of_size != len(sum_of_set) or mul_of_size != lines:
        print("NO")
        return

    print("YES")
    for set_ in res_types:
        for char in sorted(set_):
            print(char, end="")
        print()


if __name__ == "__main__":
    main()
