# BOJ-23629 / 이 얼마나 끔찍하고 무시무시한 수식이니
# devgeon, 2024.01.18, Python3
# https://www.acmicpc.net/problem/23629


DICT = [
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",
]
OPERATOR = ["+", "-", "x", "/"]


def str_to_int(string: str) -> int:
    if string == "":
        raise ValueError
    result = ""
    i = 0
    while i < len(string) - 1:
        found = False
        for n, s in enumerate(DICT):
            if s == string[i : i + len(s)]:
                found = True
                result += str(n)
                i += len(s)
                break
        if not found:
            raise ValueError
    return int(result) * (-1 if string[0] == "-" else 1)


def int_to_str(integer: int) -> str:
    result = ""
    if integer < 0:
        result += "-"
        integer *= -1
    for n in str(integer):
        result += DICT[int(n)]
    return result


def find_operator(string: str, start: int = 0) -> int:
    for i, c in enumerate(string[start:]):
        if c in OPERATOR:
            return i + start
    return -1


def main():
    expression = input()
    new_expression = ""
    result = 0
    last_operator = "+"

    i = 0
    while last_operator != "=":
        operator_idx = find_operator(expression, i)
        try:
            number = str_to_int(expression[i:operator_idx])
        except ValueError:
            print("Madness!")
            return

        if last_operator == "+":
            result += number
        elif last_operator == "-":
            result -= number
        elif last_operator == "x":
            result *= number
        else:
            result = int(result / number)

        last_operator = expression[operator_idx]
        new_expression += f"{str(number)}{last_operator}"
        i = operator_idx + 1

    print(new_expression)
    print(int_to_str(result))


if __name__ == "__main__":
    main()
