// BOJ-18108 / 1998년생인 내가 태국에서는 2541년생?!
// devgeon, 2022.04.03, C99
// https://www.acmicpc.net/problem/18108
 
// 1천 이상 3천 이하의 불기 연도를 입력받아
// 서기 연도로 변환한 결과를 출력한다.

#include<stdio.h>

#define DIFF 543

int main()
{
	int year = 0;
	
	scanf("%d", &year);
	year -= DIFF;
	printf("%d\n", year);
	
    return 0;
}
