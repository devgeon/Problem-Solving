// BOJ-02908 / 상수
// devgeon, 2022.05.16, C99
// https://www.acmicpc.net/problem/2908
 
// 세 자리 수 두 개를 거꾸로 읽었을 때, 더 큰 수를 거꾸로 출력하는 프로그램을 작성하시오.
// 예를 들어, 734와 893이 주어진다면, 437과 398로 읽어야 하므로 437을 출력해야 한다.
// 입력: 첫째 줄에 두 수 A와 B가 주어진다. 두 수는 서로 다른 세 자리 수이며, 0이 포함되어 있지 않다.
// 출력: 첫째 줄에 거꾸로 읽었을 때 큰 수를 거꾸로 출력한다.


#include<stdio.h>
#define NUM_DIGITS 3

int power(int n, int exp);
int reverse(int n);

int main()
{
	int num1=0, num2=0;
	
	scanf("%d %d", &num1, &num2);
	
	num1 = reverse(num1);
	num2 = reverse(num2);
	
	printf("%d\n", num1>num2 ? num1 : num2);
	
	return 0;
}

int power(int n, int exp)
{
	if(exp==0)
		return 1;
	for(int i=1; i<exp; i++) {
		n *= n;
	}
	return n;
}

int reverse(int n)
{
	int result=0;
	
	for(int i=1; i<=NUM_DIGITS; i++) {
		result += (n%10) * power(10,NUM_DIGITS-i);
		n/=10;
	}
	return result;
}
