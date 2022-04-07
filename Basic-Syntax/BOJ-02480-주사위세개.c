// BOJ-02480 / 주사위 세 개
// devgeon, 2022.04.07, C99
// https://www.acmicpc.net/problem/2480
 
// 주사위 3개를 던져서 다음 규칙에 따라 상금을 받는 게임이 있다.
// 1. 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
// 2. 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
// 3. 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.
// 3개 주사위의 눈이 주어질 때, 상금을 계산하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 3개의 눈이 빈칸을 사이에 두고 각각 주어진다.
// 출력: 첫째 줄에 상금을 출력한다.
// 예시: 3,3,6 -> 1000+3*100 = 1300원
//      2,2,2 -> 10000+2*1000 = 12000원
//      6,2,5 -> 6*100 = 600원

// 참고사항
// 주사위의 개수가 바뀌더라도 적용할 수 있는 코드를 작성하고자 기존 문제 조건에 위배되지
// 않는 선에서 다음과 같이 조건을 수정하였다.
// - 같은 눈이 나온 주사위의 개수를 n이라고 할 때 상금을 계산하는 규칙은 다음과 같다.
// - 같은 눈이 2개 이상 나왔을 때, 상금은 10**(n+1)+(같은 눈)*10**n원이다.
// - 모두 다른 눈이 나오는 경우에는 기존과 같이 계산한다.


#include<stdio.h>

#define N 3  // N_MAX == 8

int power(int a, int b);

int check_dice(int dice[]);

int main()
{
	int dice[N] = {0};
	int num = 0, count = 0, price = 0, temp = 0;
	
	for(int i=0; i<N; i++) {
		scanf("%d", &dice[i]);
	}
	
	temp = check_dice(dice);
	while(temp>0) {
		num = temp;
		temp /= 10;
		count++;
	}
	
	if(count==1) {
		price = num*100;
	} else {
		price = power(10,count+1) + (num * power(10,count));
	}

	printf("%d", price);
	
    return 0;
}

int power(int a, int b)
{
	int result=1;
	for(int i=0; i<b; i++) {
		result *= a;
	}
	return result;
}

int check_dice(int dice[])
{
	int dist[6] = {0};  // distribution
	int result = 0;
	
	for(int i=0; i<N; i++) {
		dist[dice[i]-1]++;
	}
	
	for(int j=N; j>=1; j--) {
		for(int i=5; i>=0; i--) {
			if(dist[i]==j) {
				result = (i+1)*power(10,j-1);
				break;
			}
		}
		if(result!=0) {
			break;
		}
	}

	return result;
}
