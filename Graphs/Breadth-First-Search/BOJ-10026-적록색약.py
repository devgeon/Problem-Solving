# BOJ-10026 / 적록색약
# devgeon, 2023.04.23, Python3
# https://www.acmicpc.net/problem/10026


import sys
from collections import deque
readline = sys.stdin.readline


def main():
    CRITERIA = ["normal", "daltonism"]
    img_len = int(readline())
    cluster_count = dict(zip(CRITERIA, [0, 0]))

    image = [None for _ in range(img_len)]
    for i in range(img_len):
        image[i] = list(readline().rstrip())

    search_queue = deque()
    for search_by in CRITERIA:
        for i in range(img_len ** 2):
            x, y = i % img_len, i // img_len
            if search_by == "normal" and image[y][x].islower() or \
               search_by == "daltonism" and image[y][x] == "N":
                continue
            search_target = image[y][x]
            search_queue.append((x, y))
            if search_by == "normal":
                image[y][x] = "r" if image[y][x] == "G" else image[y][x].lower()
            elif search_by == "daltonism":
                image[y][x] = "N"

            while len(search_queue) != 0:
                cur_x, cur_y = search_queue.popleft()
                for dist_x, dist_y in [(0, -1), (-1, 0), (1, 0), (0, 1)]:
                    if cur_x + dist_x < 0 or cur_x + dist_x >= img_len or \
                       cur_y + dist_y < 0 or cur_y + dist_y >= img_len:
                        continue

                    if image[cur_y + dist_y][cur_x + dist_x] == search_target:
                        search_queue.append((cur_x + dist_x, cur_y + dist_y))
                        if search_by == "normal":
                            image[cur_y + dist_y][cur_x + dist_x] = ("r" if image[cur_y][cur_x] == "G"
                                                                     else image[cur_y][cur_x].lower())
                        elif search_by == "daltonism":
                            image[cur_y + dist_y][cur_x + dist_x] = "N"

            cluster_count[search_by] += 1

    print(f"{cluster_count[CRITERIA[0]]} {cluster_count[CRITERIA[1]]}")


if __name__ == "__main__":
    main()
