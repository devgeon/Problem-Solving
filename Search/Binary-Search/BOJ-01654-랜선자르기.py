# BOJ-01654 / 랜선 자르기
# devgeon, 2023.04.30, Python3
# https://www.acmicpc.net/problem/1654


import sys
from collections import deque
from math import ceil

INT32_MAX = 2147483647
readline = sys.stdin.readline


def cut_wire(cut_len: int, len_info: deque):
    wire_count = 0
    if cut_len == 0:
        return INT32_MAX
    for wire_len in len_info:
        wire_count += wire_len // cut_len
    return wire_count


def main():
    cur_num, req_num = [int(n) for n in readline().rstrip().split(" ")]
    len_info = deque()
    max_len = 0
    for _ in range(cur_num):
        cur_len = int(readline())
        if cur_len > max_len:
            max_len = cur_len
        len_info.append(cur_len)

    cut_len = max_len
    max_cut_len = 0
    diff = ceil(max_len / 2)
    almost_done = False
    while True:
        wire_count = cut_wire(cut_len, len_info)
        if wire_count < req_num:
            if almost_done:
                break
            cut_len -= diff
        else:
            if max_cut_len < cut_len:
                max_cut_len = cut_len
            if diff == 1 and not almost_done:
                almost_done = True
            cut_len += diff
        diff = ceil(diff / 2)

    print(max_cut_len)


if __name__ == "__main__":
    main()
