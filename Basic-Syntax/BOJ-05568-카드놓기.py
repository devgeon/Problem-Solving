# BOJ-05568 / 카드 놓기
# devgeon, 2022.09.03, PyPy3
# https://www.acmicpc.net/problem/5568
 
# 1 이상 99 이하의 정수가 각각 적혀있는 n(4 ≤ n ≤ 10)장의 카드 중에서 k(2 ≤ k ≤ 4)장을 선택하고,
# 가로로 나열하여 정수를 만드려고 할 때, 만들 수 있는 정수의 개수를 구하는 프로그램을 작성하시오.

# 입력: 첫째 줄에 n이, 둘째 줄에 k가 주어진다. 셋째 줄부터 n개 줄에는 카드에 적혀있는 수가 주어진다.
# 출력: 만들 수 있는 정수의 개수를 출력한다.


def select_numbers(numbers:list, count:int):
    result = list()
    for i in range(len(numbers)):
        for j in range(i+1,len(numbers)):
            if count == 2:
                result.append((numbers[i],numbers[j]))
            else:
                for k in range(j+1, len(numbers)):
                    if count == 3:
                        result.append((numbers[i],numbers[j],numbers[k]))
                    else:
                        for l in range(k+1, len(numbers)):
                            result.append((numbers[i],numbers[j],numbers[k],numbers[l]))
    return result

def shuffle_numbers(numbers:list, result:set):
    if len(numbers[0]) == 2:
        for num_tup in numbers:
            result.add(num_tup[0]+num_tup[1])
            result.add(num_tup[1]+num_tup[0])
    elif len(numbers[0]) == 3:
        for num_tup in numbers:
            result.add(num_tup[0]+num_tup[1]+num_tup[2])
            result.add(num_tup[0]+num_tup[2]+num_tup[1])
            result.add(num_tup[1]+num_tup[0]+num_tup[2])
            result.add(num_tup[1]+num_tup[2]+num_tup[0])
            result.add(num_tup[2]+num_tup[0]+num_tup[1])
            result.add(num_tup[2]+num_tup[1]+num_tup[0])
    else:
        for num_tup in numbers:
            result.add(num_tup[0]+num_tup[1]+num_tup[2]+num_tup[3])
            result.add(num_tup[0]+num_tup[1]+num_tup[3]+num_tup[2])
            result.add(num_tup[0]+num_tup[2]+num_tup[1]+num_tup[3])
            result.add(num_tup[0]+num_tup[2]+num_tup[3]+num_tup[1])
            result.add(num_tup[0]+num_tup[3]+num_tup[1]+num_tup[2])
            result.add(num_tup[0]+num_tup[3]+num_tup[2]+num_tup[1])
            result.add(num_tup[1]+num_tup[0]+num_tup[2]+num_tup[3])
            result.add(num_tup[1]+num_tup[0]+num_tup[3]+num_tup[2])
            result.add(num_tup[1]+num_tup[2]+num_tup[0]+num_tup[3])
            result.add(num_tup[1]+num_tup[2]+num_tup[3]+num_tup[0])
            result.add(num_tup[1]+num_tup[3]+num_tup[0]+num_tup[2])
            result.add(num_tup[1]+num_tup[3]+num_tup[2]+num_tup[0])
            result.add(num_tup[2]+num_tup[1]+num_tup[0]+num_tup[3])
            result.add(num_tup[2]+num_tup[1]+num_tup[3]+num_tup[0])
            result.add(num_tup[2]+num_tup[0]+num_tup[1]+num_tup[3])
            result.add(num_tup[2]+num_tup[0]+num_tup[3]+num_tup[1])
            result.add(num_tup[2]+num_tup[3]+num_tup[1]+num_tup[0])
            result.add(num_tup[2]+num_tup[3]+num_tup[0]+num_tup[1])
            result.add(num_tup[3]+num_tup[1]+num_tup[2]+num_tup[0])
            result.add(num_tup[3]+num_tup[1]+num_tup[0]+num_tup[2])
            result.add(num_tup[3]+num_tup[2]+num_tup[1]+num_tup[0])
            result.add(num_tup[3]+num_tup[2]+num_tup[0]+num_tup[1])
            result.add(num_tup[3]+num_tup[0]+num_tup[1]+num_tup[2])
            result.add(num_tup[3]+num_tup[0]+num_tup[2]+num_tup[1])
    return result


def main():
    card_list = list()
    card_total_num = 0
    card_select_num = 0
    result_numbers = set()

    card_total_num = int(input())
    card_select_num = int(input())

    for i in range(card_total_num):
        card_list.append(input())

    card_select_list = select_numbers(card_list, card_select_num)
    result_numbers = shuffle_numbers(card_select_list, result_numbers)
    
    print(len(result_numbers))


if __name__ == "__main__":
    main()
