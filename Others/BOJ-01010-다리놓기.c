// BOJ-01010 / 다리 놓기
// devgeon, 2022.04.27, C99
// https://www.acmicpc.net/problem/1010
 
// 도시를 동쪽과 서쪽으로 나누는 큰 일직선 모양의 강이 흐르고 있다.
// 강 주변에서 다리를 짓기에 적합한 곳을 사이트라고 한다.
// 강 서쪽에는 N개의 사이트가, 동쪽에는 M개의 사이트가 있다. (N ≤ M)
// 한 사이트에는 최대 한 개의 다리만 연결될 수 있고, 다리 끼리는 서로 겹쳐질 수 없다.
// 서쪽 사이트 개수 만큼 다리를 지을 때, 경우의 수를 구하는 프로그램을 작성하시오.

// 입력: 입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
//      그 다음 줄부터 각각의 테스트케이스에 대해 강의 서쪽과 동쪽에 있는 사이트의 개수
//      정수 N, M (0 < N ≤ M < 30)이 주어진다.

// 출력: 각 테스트 케이스에 대해 주어진 조건하에 다리를 지을 수 있는 경우의 수를 출력한다.


// 강 동쪽 사이트 M개에서 N개를 고르고 나면 다리를 지을 수 있는 경우는 1가지 뿐이다.
// 따라서 M개 사이트 중에서 순서를 고려하지 않고 중복 없이 N개를 뽑는 경우의 수가
// 곧 다리를 지을 수 있는 경우의 수이므로 조합을 사용하여 문제를 해결할 수 있다.


#include<stdio.h>

int combination(int n, int r);

int main()
{
    int n=0;
	int west=0, east=0;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d %d", &west, &east);
		printf("%d\n", combination(east, west));
	}
	
    return 0;
}

int combination(int n, int r)
{
	if(n==r) return 1;
	int result = 1;
	for(int i=0; i<r; i++) {
		result *= (n-i);
		result /= (i+1);
	}
	return result;
}
