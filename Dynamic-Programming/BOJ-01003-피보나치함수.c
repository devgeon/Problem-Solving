// BOJ-01003 / 피보나치 함수
// devgeon, 2022.05.20, C99
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

typedef struct _Counter {
	int zero;
	int one;
} Counter;

int fibonacci(int n, Counter* counter);

int main()
{
    int t=0, num=0;
	Counter counter[MAX+1] = {0,};
	
	for(int i=0; i<MAX+1; i++) {
		counter[i].zero = -1;
		counter[i].one = -1;
	}
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++) {
		scanf("%d", &num);
		if(counter[num].one==-1) {
			fibonacci(num, counter);
		}
		printf("%d %d\n", counter[num].zero, counter[num].one);
	}
	
	return 0;
}

int fibonacci(int num, Counter* counter) {
	if(counter[num].zero!=-1) {
		return 0;
	} else if(num==0) {
		counter[num].zero = 1;
		counter[num].one = 0;
	} else if(num==1) {
		counter[num].zero = 0;
		counter[num].one = 1;
	} else {
		if(counter[num-2].zero==-1) {
			fibonacci(num-2, counter);
		}
		if(counter[num-1].zero==-1) {
			fibonacci(num-1, counter);
		}
		counter[num].zero = counter[num-1].zero + counter[num-2].zero;
		counter[num].one = counter[num-1].one + counter[num-2].one;
	}
	return 0;
}
