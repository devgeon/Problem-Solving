// BOJ-08393 / 합
// devgeon, 2022.04.08, C99
// https://www.acmicpc.net/problem/8393

// n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.
// 출력: 1부터 n까지 합을 출력한다.


#include<stdio.h>

int main()
{
	int n=0, result=0;
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++) {
		result += i;
	}
	
	printf("%d\n", result);
	
    return 0;
}
