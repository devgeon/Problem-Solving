# BOJ-05107 / 마니또
# devgeon, 2024.05.02, Python3
# https://www.acmicpc.net/problem/5107


import sys

readline = sys.stdin.readline
write = sys.stdout.write


def main():
    i = 1
    while True:
        num = int(readline())
        cycles: list[set] = []
        if num == 0:
            break

        for _ in range(num):
            name1, name2 = readline().split()
            found = False

            for group in cycles:
                if name1 in group:
                    group.add(name2)
                elif name2 in group:
                    group.add(name1)
                else:
                    continue
                found = True
                break

            if not found:
                cycles.append({name1, name2})

        write(f"{i} {len(cycles)}\n")
        i += 1


if __name__ == "__main__":
    main()
