# BOJ-32980 / 분리배출
# devgeon, 2025.04.28, Python3
# https://www.acmicpc.net/problem/32980


import sys

readline = sys.stdin.readline
write = sys.stdout.write

TYPES = ["P", "C", "V", "S", "G", "F", "O"]


def main():
    num = int(readline())
    answer = 0
    trash_costs = {}
    trash_counts = {}
    for _ in range(num):
        trash = readline().rstrip()
        trash_type = trash[0] if trash.count(trash[0]) == len(trash) else "O"
        if trash_type not in trash_counts:
            trash_counts[trash_type] = 0
        trash_counts[trash_type] += len(trash)
    for index, cost in enumerate(readline().rstrip().split()):
        trash_costs[TYPES[index]] = int(cost)
    trash_costs["O"] = int(readline())
    for key, value in trash_counts.items():
        if trash_costs[key] > trash_costs["O"]:
            key = "O"
        answer += trash_costs[key] * value
    write(str(answer))


if __name__ == "__main__":
    main()
