// BOJ-10699 / 오늘 날짜
// devgeon, 2022.05.09, C99
// https://www.acmicpc.net/problem/10699
 
// 서울의 오늘 날짜를 출력하는 프로그램을 작성하시오.
// 출력: 서울의 오늘 날짜를 "YYYY-MM-DD" 형식으로 출력한다.

#include<stdio.h>
#include<time.h>

int main()
{
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	
	printf("%d-%02d-%02d\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday);
	
    return 0;
}
