// BOJ-01003 / 피보나치 함수
// devgeon, 2022.05.05, C99
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

int fibonacci(int n, int* count);

int main()
{
    int t=0, num=0;
	int count[2] = {0,};
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++) {
		count[0] = count[1] = 0;
		scanf("%d", &num);
		fibonacci(num, count);
		printf("%d %d\n", count[0], count[1]);
	}
	
	return 0;
}

int fibonacci(int n, int* count) {
    if (n == 0) {
        count[0]++;
        return 0;
    } else if (n == 1) {
        count[1]++;
        return 1;
    } else {
        return fibonacci(n-1, count) + fibonacci(n-2, count);
    }
}
