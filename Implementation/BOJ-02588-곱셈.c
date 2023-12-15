// BOJ-02588 / 곱셈
// devgeon, 2022.04.03, C99
// https://www.acmicpc.net/problem/2588
 
// 수기로 세 자리 수끼리 곱셈을 할 때 승수를 1의 자리, 10의 자리,
// 100의 자리 수로 나누어 피승수에 곱하고 그 값을 모두 합한다.
// 두 개의 세 자리 자연수가 두 줄로 주어졌을 때, 중간 계산 과정인
// 피승수 * 승수의 1의 자리 숫자, 피승수 * 승수의 10의 자리 숫자,
// 피승수 * 승수의 100의 자리 숫자, 그리고 최종 곱셈 결과를 네 줄로 
// 출력하시오.

#include<stdio.h>

int main()
{
	int a=0, b=0, tmp=0, result=0;
	int i=1;
	
	scanf("%d %d", &a, &b);
	
	while(b>0) {
		tmp = a*(b%10);
		result += tmp*i;
		printf("%d\n", tmp);
		b /= 10;
		i *= 10;
	}
	
	printf("%d\n", result);
	
    return 0;
}
