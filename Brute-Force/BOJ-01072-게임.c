// BOJ-01072 / 게임
// devgeon, 2022.05.11, C99
// https://www.acmicpc.net/problem/1072
 
// 앞으로의 게임에서 무조건 승리한다고 가정할 때, 게임을 최소 몇 판을 더 해야 승률이 변하는지 구하는 프로그램을 작성하시오.
// 승률의 소수점은 버리며, 만약 Z가 절대 변하지 않는다면 -1을 출력한다.
// 게임 횟수를 X, 이긴 게임의 수를 Y, 승률을 Z라 할 때, X=53, Y=47이면 Z=88이다.

// 제한: 1 ≤ X ≤ 1,000,000,000
//      0 ≤ Y ≤ X

// 입력: 첫째 줄에 정수 X와 Y가 주어진다.
// 출력: 첫째 줄에 게임을 최소 몇 판 더 해야하는지 출력한다.


#include<stdio.h>

int main()
{
	long long i = 0, temp = 0;
	long long play_count = 0;
	long long win_count = 0;
	long long win_rate = 0;
	
	scanf("%lld %lld", &play_count, &win_count);
	win_rate = win_count * 100 / play_count;
	i = play_count / 100;
	
	if(win_rate>=99) {
		printf("-1\n");
		return 0;
	}
	
	do {
		temp = (win_count+i) * 100 / (play_count+i);
		i++;
	} while(win_rate==temp);
		
	printf("%lld\n", i-1);
	
	return 0;
}
