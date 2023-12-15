# BOJ-15552 / 빠른 A+B
# devgeon, 2022.04.08, Python3
# https://www.acmicpc.net/problem/15552

# 빠른 입출력 방식을 사용하여 시간초과하지 않고 최대 1,000,000개의 테스트케이스를
# 입력받아 결과를 출력하는 프로그램을 작성하시오.
# 입력: 첫 줄에 테스트케이스의 개수 T가 주어진다. T는 최대 1,000,000이다.
#      다음 T줄에는 각각 두 정수 A와 B가 주어진다. A와 B는 1 이상, 1,000 이하이다.
# 출력: 각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다.

# 참고1. Python을 사용하고 있다면, input 대신 sys.stdin.readline을 사용할 수 있다.
#       단, 이때는 맨 끝의 개행문자까지 같이 입력받기 때문에 문자열을 저장하고 싶을 경우
#       .rstrip()을 추가로 해 주는 것이 좋다.
# 참고2. 입력과 출력 스트림은 별개이므로, 테스트케이스를 전부 입력받아서 저장한 뒤 전부
#       출력할 필요는 없다. 테스트케이스를 하나 받은 뒤 하나 출력해도 된다.
# 참고3. BOJ 작동 원리, https://www.acmicpc.net/blog/view/55


import sys

def fast_input():
    input = sys.stdin.readline

    n = int(input())

    i=0
    while(i<n):
        temp = input().split(" ")
        a = int(temp[0])
        b = int(temp[1])
        print(a+b)
        i+=1

def default_input():
    n = int(input())

    i=0
    while(i<n):
        temp = input().split(" ")
        a = int(temp[0])
        b = int(temp[1])
        print(a+b)
        i+=1

fast_input()
