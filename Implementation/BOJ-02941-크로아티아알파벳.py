# BOJ-02941 / 크로아티아 알파벳
# devgeon, 2024.12.05, Python3
# https://www.acmicpc.net/problem/2941

import sys

readline = sys.stdin.readline
write = sys.stdout.write


def main():
    text = readline().rstrip()
    croatia = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
    for alpha in croatia:
        text = text.replace(alpha, ".")
    write(str(len(text)))


if __name__ == "__main__":
    main()
