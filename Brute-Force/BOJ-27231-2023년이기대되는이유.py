# BOJ-27231 / 2023년이 기대되는 이유
# devgeon, 2023.02.23, PyPy3
# https://www.acmicpc.net/problem/27231

import sys
readline = sys.stdin.readline

# 0 또는 1로만 이루어진 수인지 확인하는 함수
def is_zero_one(num):
    for char in str(num):
        if char == '0' or char == '1':
            pass
        else:
            return False
    return True

# 각 자리 수 n 제곱하여 합한 값을 반환하는 함수
def calc_powers(num):
    result = []
    parse_num = [int(x) for x in str(num)]
    temp_num = [*parse_num]
    result.append(sum(parse_num))
    while True:
        temp_num = [temp_num[i] * parse_num[i] for i in range(len(parse_num))]
        temp_sum = sum(temp_num)
        if temp_sum <= num:
            result.append(temp_sum)
        else:
            break
    return result

# 덧셈 기호를 넣어 계산한 모든 값을 반환하는 함수
def calc_sums(num):
    result = [num]
    str_num = str(num)
    if len(str_num) == 1:
        return [num]
    for i in range(1, len(str_num)):
        fix_num = int(str_num[:i])
        add_nums = calc_sums(int(str_num[i:]))
        result += [x + fix_num for x in add_nums]
    return result

def main():
    test_case = int(readline())
    for _ in range(test_case):
        match = 0
        num = int(readline())
    
        if is_zero_one(num):
            match = -1
        elif len(str(num)) == 1:
            match = 1
        else:
            powers = set(calc_powers(num))
            sums = set(calc_sums(num))
            match = len(powers.intersection(sums))
        
        if match == -1:
            print("Hello, BOJ 2023!")
        else:
            print(match)

if __name__ == "__main__":
    main()
