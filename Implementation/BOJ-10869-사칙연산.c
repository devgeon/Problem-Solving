// BOJ-10869-사칙연산.c
// devgeon, 2022.03.31
// https://www.acmicpc.net/problem/10869
 
// 두 자연수 A와 B가 주어진다. 이때, A+B, A-B, A*B, A/B(몫),
// A%B(나머지)를 출력하는 프로그램을 작성하시오

#include<stdio.h>

int main()
{
	int a=0, b=0;
	scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
	printf("%d\n", a-b);
	printf("%d\n", a*b);
	printf("%d\n", a/b);
	printf("%d\n", a%b);
    return 0;
}
