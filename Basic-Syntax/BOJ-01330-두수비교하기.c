// BOJ-01330 / 두 수 비교하기
// devgeon, 2022.04.04, C99
// https://www.acmicpc.net/problem/1330
 
// 두 정수가 주어졌을 때 서로 비교하는 프로그램을 작성하시오.
// 입력: 두 정수 A, B가 공백 한 칸으로 구분되어 주어진다.
// 출력: A가 B보다 큰 경우 ">"를, A가 B보다 작은 경우에는 "<"를,
//      A와 B가 같은 경우에는 "=="를 출력한다.

#include<stdio.h>

int main()
{
	int a=0, b=0;
	
	scanf("%d %d", &a, &b);
	
	if(a>b) {
		printf(">");
	} else if(a<b) {
		printf("<");
	} else {
		printf("==");
	}
	
    return 0;
}
