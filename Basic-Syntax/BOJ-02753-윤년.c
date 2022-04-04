// BOJ-02753 / 윤년
// devgeon, 2022.04.04, C99
// https://www.acmicpc.net/problem/2753
 
// 연도(1 이상, 4000 이하 자연수)가 주어졌을 때 윤년이면 1, 아니면 0을
// 출력하는 프로그램을 작성하시오.
// 윤년은 연도가 4의 배우시면서 100의 배수가 아닐 때, 혹은 400의 배수일 때이다.

#include<stdio.h>

int main()
{
	int year=0;
	
	scanf("%d", &year);
	
	if((year%4==0 && year%100!=0) || year%400==0) {
		printf("1");
	} else {
		printf("0");
	}
	
    return 0;
}
