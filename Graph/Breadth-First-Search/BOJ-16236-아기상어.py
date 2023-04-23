# BOJ-16236 / 아기 상어
# devgeon, 2023.04.23, Python3
# https://www.acmicpc.net/problem/16236


import sys
from collections import deque
readline = sys.stdin.readline
MAX_FISH_SIZE = 6  # 9 미만의 정수


def main():
    shark_size, shark_exp = 2, 0
    fish_count, time_count = 0, 0
    board_size = int(readline())

    board = [[0 for _ in range(board_size)] for _ in range(board_size)]
    for y in range(board_size):
        board_line = [int(n) for n in readline().rstrip().split(" ")]
        for x, num in enumerate(board_line):
            if num > 0 and num < MAX_FISH_SIZE + 1:
                fish_count += 1
                board[y][x] = num
            elif num == 9:
                start_x, start_y = x, y

    search_queue = deque()
    visited = deque()
    for _ in range(fish_count):
        search_queue.append((start_x, start_y))
        search_queue.append((-1, -1))
        nearby_fish = []
        temp_time = 0
        while not len(search_queue) == 0:
            cur_x, cur_y = search_queue.popleft()
            # 특정 거리에 위치한 모든 칸을 탐색 완료한 경우
            if cur_x == -1:
                # 물고기 먹을 수 없는 경우 더 먼 거리 탐색
                if len(nearby_fish) == 0:
                    # 더 탐색할 칸이 없는 경우 루프 탈출
                    if len(search_queue) == 0:
                        break
                    search_queue.append((-1, -1))
                    temp_time += 1
                    continue
                # 물고기를 먹을 수 있는 경우
                else:
                    # 물고기 여러 마리일 경우 조건에 맞게 선택
                    nearby_fish.sort(key=lambda pos: pos[0])
                    nearby_fish.sort(key=lambda pos: pos[1])
                    target_x, target_y = nearby_fish[0]
                    # 물고기 먹기
                    shark_exp += 1
                    if shark_exp == shark_size:
                        shark_size += 1
                        shark_exp = 0
                    board[target_y][target_x] = 0
                    time_count += temp_time + 1
                    # 시작 지점 갱신
                    start_x, start_y = target_x, target_y
                    # 큐 및 포함 기록(음수 표기) 초기화
                    for queue in [search_queue, visited, nearby_fish[1:]]:
                        while len(queue) > 0:
                            temp_x, temp_y = queue.pop()
                            if board[temp_y][temp_x] < 0:
                                board[temp_y][temp_x] += MAX_FISH_SIZE + 1
                    # 시작 지점 갱신을 위해 루프 탈출
                    break

            # 특정 거리에 위치한 칸 탐색을 모두 마치지 못한 경우
            else:
                # 큐 포함 기록(음수 표기) 초기화를 위해 다시 기록
                if board[cur_y][cur_x] < 0:
                    visited.append((cur_x, cur_y))
                # 가져온 좌표에서 거리 1칸 이내인 칸을 모두 확인
                for dist_x, dist_y in [(0, -1), (-1, 0), (1, 0), (0, 1)]:
                    target_x, target_y = cur_x + dist_x, cur_y + dist_y
                    # 외곽 범위 검사
                    if target_x < 0 or target_x >= board_size or target_y < 0 or target_y >= board_size:
                        continue
                    # 이미 큐나 물고기 목록에 있거나 지나가지 못하는 칸 패스
                    elif board[target_y][target_x] < 0 or board[target_y][target_x] > shark_size:
                        continue

                    # 지나갈 수 있는 길
                    if board[target_y][target_x] == 0 or board[target_y][target_x] == shark_size:
                        # 큐에 포함된 칸 기록 (음수 표기)
                        board[target_y][target_x] -= MAX_FISH_SIZE + 1
                        search_queue.append((cur_x + dist_x, cur_y + dist_y))
                    # 물고기 먹을 수 있는 칸
                    elif board[target_y][target_x] < shark_size:
                        # 가까운 물고기 목록에 추가하기
                        nearby_fish.append((target_x, target_y))
                        board[target_y][target_x] -= MAX_FISH_SIZE + 1

        # 이번 탐색에 물고기를 먹지 못했을 경우 종료
        # if shark_exp + (shark_size - 1) * shark_size // 2 - 2 != i:
        if len(nearby_fish) == 0:
            break

    print(time_count)


if __name__ == "__main__":
    main()
