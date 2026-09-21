# JOL-21016 / RLE 압축
# devgeon, 2026.09.21, Python3
# https://jungol.co.kr/problem/21016


def main():
    text = input()

    cnt, prev = 0, text[0]
    answer = ""
    for c in text:
        if c == prev:
            cnt += 1
            continue
        answer += str(cnt) + prev
        prev = c
        cnt = 1
    answer += str(cnt) + prev

    print(answer)


if __name__ == "__main__":
    main()
