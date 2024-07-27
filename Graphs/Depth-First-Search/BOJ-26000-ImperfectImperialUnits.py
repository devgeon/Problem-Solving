# BOJ-26000 / Imperfect Imperial Units
# devgeon, 2024.07.27, Python3
# https://www.acmicpc.net/problem/26000


import sys
from typing import Optional

readline = lambda: sys.stdin.readline().rstrip()


def find_ratio(
    table: dict, unit1: str, unit2: str, visited: set = None
) -> Optional[float]:
    if unit1 in table and unit2 in table[unit1]:
        return table[unit1][unit2]
    if visited is None:
        visited = set()
    visited.add(unit1)
    for temp_unit in table[unit1]:
        if temp_unit in visited:
            continue
        ratio = find_ratio(table, temp_unit, unit2, visited)
        if ratio:
            ratio *= table[unit1][temp_unit]
            table[unit1][unit2] = ratio
            return ratio
    return None


def main():
    num_of_equations, num_of_queries = [int(x) for x in readline().split()]
    table = {}

    for _ in range(num_of_equations):
        _, unit1, _, ratio, unit2 = readline().split()
        ratio = float(ratio)
        if unit1 not in table:
            table[unit1] = {}
        if unit2 not in table:
            table[unit2] = {}
        table[unit1][unit2] = ratio
        table[unit2][unit1] = 1 / ratio

    for _ in range(num_of_queries):
        value, unit1, _, unit2 = readline().split()
        ratio = find_ratio(table, unit1, unit2)
        if ratio:
            print(float(value) * ratio)
        else:
            print("impossible")


if __name__ == "__main__":
    main()
