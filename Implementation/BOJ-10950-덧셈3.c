// BOJ-10950 / A+B-3
// devgeon, 2022.04.08, C99
// https://www.acmicpc.net/problem/10950
 
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
//      각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
// 출력: 각 테스트 케이스마다 A+B를 출력한다.


#include<stdio.h>

int main()
{
	int n=0, a=0, b=0;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	
    return 0;
}
