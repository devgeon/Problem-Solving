// BOJ-01065 / 한수
// devgeon, 2022.05.12, C99
// https://www.acmicpc.net/problem/1065
 
// 어떤 양의 정수 X의 각 자리가 등차수열을 이루면, X는 한수이다.
// N이 주어졌을 때, 1 이상 N 이하인 한수의 개수를 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 1000 이하인 자연수 N이 주어진다.
// 출력: 첫째 줄에 1 이상 N 이하인 한수의 개수를 출력한다.


#include<stdio.h>

int check(int num);

int main()
{
	int n=0;
	int count=0;
	
	scanf("%d", &n);
	
	if(n<100) {
		printf("%d\n", n);
		return 0;
	}
	
	count=99;
	for(int i=100; i<=n; i++) {
		count += check(i);
	}
	
	printf("%d\n", count);
	
	return 0;
}

int check(int num) {  // num >= 100
	int d=0;
	int last_d=0;
	
	last_d = (num/10)%10 - num%10;
	num /= 10;
	while((num/10)>0) {
		d = (num/10)%10 - num%10;
		if(last_d != d) {
			return 0;
		}
		num /= 10;
		last_d = d;
	}
	return 1;
}
