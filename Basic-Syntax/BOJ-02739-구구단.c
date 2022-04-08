// BOJ-02739 / 구구단
// devgeon, 2022.04.08, C99
// https://www.acmicpc.net/problem/2739
 
// N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 N(1 ≤ N ≤ 9)이 주어진다.
// 출력: 출력 형식과 같게 N*1부터 N*9까지 출력한다.


#include<stdio.h>

int main()
{
	int n=0;
	
	scanf("%d", &n);
	
	for(int i=1; i<10; i++) {
		printf("%d * %d = %d\n", n, i, n*i);
	}
	
    return 0;
}
