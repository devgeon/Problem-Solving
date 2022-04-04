// BOJ-09498 / 시험 성적
// devgeon, 2022.04.04, C99
// https://www.acmicpc.net/problem/9498
 
// 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B,
// 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력
// 하는 프로그램을 작성하시오.
// 입력: 0이상 100이하의 시험 점수가 주어진다.
// 출력: 시험 성적을 출력한다.

#include<stdio.h>

int main()
{
	int score=0;
	char grade=0;
	
	scanf("%d", &score);
	
	switch(score/10) {
		case 10:
		case 9:
			grade = 'A';
			break;
		case 8:
			grade = 'B';
			break;
		case 7:
			grade = 'C';
			break;
		case 6:
			grade = 'D';
			break;
		default:
			grade = 'F';
	}
	
	printf("%c", grade);
	
    return 0;
}
