// BOJ-10430 / 나머지
// devgeon, 2022.04.03, C99
// https://www.acmicpc.net/problem/10430
 
// 세 수 A, B, C가 주어졌을 때, 다음 네 가지 값을 구하는 프로그램을 작성하시오
// 입력: 첫째 줄에 A, B, C가 순서대로 주어진다 (2 ≤ A, B, C ≤ 10000)
// 출력: 첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C,
//      넷째 줄에 ((A%C) × (B%C))%C를 출력한다

#include<stdio.h>

int main()
{
	int a=0, b=0, c=0;
	
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", (a+b)%c);
	printf("%d\n", ((a%c)+(b%c))%c);
	printf("%d\n", (a*b)%c);
	printf("%d\n", ((a%c)*(b%c))%c);
	
    return 0;
}
