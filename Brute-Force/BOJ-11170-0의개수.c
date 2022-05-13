// BOJ-11170 / 0의 개수
// devgeon, 2022.05.13, C99
// https://www.acmicpc.net/problem/11170
 
// N부터 M까지의 수들을 종이에 적었을 때, 종이에 적힌 0의 개수를 세는 프로그램을 작성하시오.
// 입력: 첫 번째 줄에 테스트 케이스의 수 T가 주어진다. (1 ≤ T ≤ 20)
//      각 줄에는 N과 M이 주어진다. (0 ≤ N ≤ M ≤ 1,000,000)
// 출력: 각각의 테스트 케이스마다 N부터 M까지의 0의 개수를 출력한다.


#include<stdio.h>

int countZero(int num);

int main()
{
	int n=0, count=0;
	int start=0, end=0;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		count = 0;
		scanf("%d %d", &start, &end);
		for(int num=start; num<=end; num++) {
			count += countZero(num);
		}
		printf("%d\n", count);
	}
	
	return 0;
}

int countZero(int num)
{
	int count=0;
	if(num==0) count=1;
	while(num>0) {
		if(num%10==0) {
			count++;
		}
		num/=10;
	}
	return count;
}
