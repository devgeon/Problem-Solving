// BOJ-01003 / 피보나치 함수
// devgeon, 2022.05.06, C99
// https://www.acmicpc.net/problem/1003
 
// 주어진 피보나치 수를 구하는 함수 fibonacci()를 참고하여 fibonacci(N)을 호출했을 때
// 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

// int fibonacci(int n) {
//     if (n == 0) {
//         printf("0");
//         return 0;
//     } else if (n == 1) {
//         printf("1");
//         return 1;
//     } else {
//         return fibonacci(n‐1) + fibonacci(n‐2);
//     }
// }

// 입력: 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
//      각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다.
//      N은 40보다 작거나 같은 자연수 또는 0이다.

// 출력: 각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.


#include<stdio.h>
#define MAX 40

int fibonacci(int n, int* count_zero, int* count_one);

int main()
{
    int t=0, num=0;
	int count_zero[MAX+1];
	int count_one[MAX+1];
	
	for(int i=0; i<MAX+1; i++) {
		count_zero[i] = -1;
		count_one[i] = -1;
	}
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++) {
		scanf("%d", &num);
		if(count_one[num]==-1) {
			fibonacci(num, count_zero, count_one);
		}
		printf("%d %d\n", count_zero[num], count_one[num]);
	}
	
	return 0;
}

int fibonacci(int num, int* count_zero, int* count_one) {
	if(count_zero[num]!=-1) {
		return 0;
	} else if(num==0) {
		count_zero[num] = 1;
		count_one[num] = 0;
	} else if(num==1) {
		count_zero[num] = 0;
		count_one[num] = 1;
	} else {
		if(count_zero[num-2]==-1) {
			fibonacci(num-2, count_zero, count_one);
		}
		if(count_zero[num-1]==-1) {
			fibonacci(num-1, count_zero, count_one);
		}
		count_zero[num] = count_zero[num-1] + count_zero[num-2];
		count_one[num] = count_one[num-1] + count_one[num-2];
	}
	return 0;
}
