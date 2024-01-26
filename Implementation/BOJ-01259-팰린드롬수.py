# BOJ-01259 / 팰린드롬수
# devgeon, 2024.01.26, Python3
# https://www.acmicpc.net/problem/1259


def check_palindrome_number(num: int) -> bool:
    num = str(num)
    for i in range(0, len(num) // 2 + 1):
        if num[i] != num[-i - 1]:
            return False
    return True


def main():
    while True:
        num = int(input())
        if num == 0:
            break
        print("yes" if check_palindrome_number(num) else "no")


if __name__ == "__main__":
    main()
