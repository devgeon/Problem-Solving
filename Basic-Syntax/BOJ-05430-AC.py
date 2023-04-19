# BOJ-05430 / AC
# devgeon, 2023.04.19, PyPy3
# https://www.acmicpc.net/problem/5430


def main():
    times = int(input())

    for _ in range(times):
        function = input()
        if input() == "0":
            _ = input()
            array = []
        else:
            array = [int(n) for n in input()[1:-1].split(",")]
        start, end, step = 0, len(array), 1
        reverse = False
        buffer = None

        for command in function:
            if command == "R":
                reverse = not reverse
            else:
                if reverse:
                    end -= 1
                else:
                    start += 1
            if start > end:
                buffer = "error"
                break

        if buffer is None:
            if reverse:
                step = -1
            buffer = str(array[start:end][::step]).replace(" ", "")

        print(buffer)


if __name__ == "__main__":
    main()
