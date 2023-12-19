# BOJ-09363 / 큰 나눗셈
# devgeon, 2023.12.19, PyPy3
# https://www.acmicpc.net/problem/9363


import sys

NUM_MAX = 1000000
input = sys.stdin.readline


def get_prime_factors(num: int, cache: list) -> list:
    if cache[num - 2]:
        return cache[num - 2]

    n = 2
    while n**2 <= NUM_MAX:
        if num % n == 0:
            cache[num - 2] = [n] + get_prime_factors(num // n, cache)
            return cache[num - 2]
        n += 1

    return [num]


def main():
    case_num = 1
    total_cases = int(input())
    cache = [[] for _ in range(2, NUM_MAX + 1)]
    output = ""

    while case_num <= total_cases:
        _ = input()  # 수열 길이 입력 생략
        numerator_factors = {}
        denominator_factors = {}

        # 분자, 분모 입력 및 소인수분해
        for factors in [numerator_factors, denominator_factors]:
            for num in [int(x) for x in input().split()]:
                for prime in get_prime_factors(num, cache):
                    if prime in factors:
                        factors[prime] += 1
                    else:
                        factors[prime] = 1

        # 분자, 분모 약분 및 최종값 연산
        numerator = 1
        denominator = 1
        for factor, count in denominator_factors.items():
            if factor not in numerator_factors:
                denominator *= factor**count
                continue
            if numerator_factors[factor] < count:
                denominator *= factor ** (count - numerator_factors[factor])
            else:
                numerator *= factor ** (numerator_factors[factor] - count)
            del numerator_factors[factor]
        for factor, count in numerator_factors.items():
            numerator *= factor**count

        output += f"Case #{case_num}: {numerator} / {denominator}\n"
        case_num += 1

    print(output)


if __name__ == "__main__":
    main()
