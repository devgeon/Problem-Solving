# BOJ-06325 / Definite Values
# devgeon, 2025.04.24, Python3
# https://www.acmicpc.net/problem/6325


import sys

readline = sys.stdin.readline
write = sys.stdout.write


def main():
    i = 1
    while True:
        var_set = set("a")
        num = int(readline())
        if num == 0:
            break

        for _ in range(num):
            define = readline().rstrip().split(" ")
            if define[2] in var_set:
                var_set.add(define[0])
            elif define[0] in var_set:
                var_set.remove(define[0])

        write(f"Program #{i}\n")
        write(f"{'none' if len(var_set) == 0 else ' '.join(sorted(list(var_set)))}\n\n")
        i += 1


if __name__ == "__main__":
    main()
