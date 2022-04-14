// BOJ-10818 / 최소, 최대
// devgeon, 2022.04.14, C99
// https://www.acmicpc.net/problem/10818

// N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
//      둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
//      모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
// 출력: 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.


#include<stdio.h>

int main()
{
	int n=0, temp=0, max=0, min=0;
	
	scanf("%d", &n);
	
	scanf("%d", &temp);
	max = min = temp;
	
	for(int i=1; i<=n; i++) {
		if(temp>max) {
			max = temp;
		} else if(temp<min) {
			min = temp;
		}
		if(i!=n) {
			scanf("%d", &temp);
		}
	}
	
	printf("%d %d\n", min, max);
	
    return 0;
}
