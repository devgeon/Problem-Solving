# BOJ-02477 / 참외밭
# devgeon, 2024.01.02, Python3
# https://www.acmicpc.net/problem/2477


import sys

input = sys.stdin.readline


def main():
    melon_yield = int(input())
    edges = [tuple(map(int, input().split())) for _ in range(6)]
    big_edges = [0, 0]
    big_edge_indices = [0, 0]

    for index, data in enumerate(edges):
        direction, length = data
        if big_edges[(direction - 1) // 2] < length:
            big_edges[(direction - 1) // 2] = length
            big_edge_indices[(direction - 1) // 2] = index

    index_filter = [sum(i) % 6 for i in zip(big_edge_indices * 3, [-1, -1, 0, 0, 1, 1])]
    small_edges = [d[1] for i, d in enumerate(edges) if i not in index_filter]

    big_rectangle = big_edges[0] * big_edges[1]
    small_rectangle = small_edges[0] * small_edges[1]
    result = (big_rectangle - small_rectangle) * melon_yield

    print(result)


if __name__ == "__main__":
    main()
