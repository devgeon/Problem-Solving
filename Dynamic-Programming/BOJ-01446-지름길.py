# BOJ-01446 / 지름길
# devgeon, 2023.11.20, Python3
# https://www.acmicpc.net/problem/1446


def main():
    n, total_length = [int(x) for x in input().split()]

    road_data = list()
    for _ in range(n):
        origin, destination, length = [int(x) for x in input().split()]
        if destination <= total_length and length < destination - origin:
            road_data.append((origin, destination, length))
    road_data.sort(reverse=True)

    road_cost = [i for i in range(total_length + 1)]
    while road_data and road_data[-1][0] == 0:
        _, destination, length = road_data.pop()
        road_cost[destination] = min(road_cost[destination], length)
    for i in range(1, total_length + 1):
        road_cost[i] = min(road_cost[i], road_cost[i - 1] + 1)
        while road_data and road_data[-1][0] == i:
            _, destination, length = road_data.pop()
            road_cost[destination] = min(road_cost[destination], road_cost[i] + length)

    print(road_cost[total_length])


if __name__ == "__main__":
    main()
