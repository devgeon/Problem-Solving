// BOJ-18111 / 마인크래프트
// devgeon, 2022.05.03, C99
// https://www.acmicpc.net/problem/18111
 
// 가로 M, 세로 N 크기의 집터 내의 땅의 높이를 모두 동일하게 만드는 '땅 고르기' 작업을 해야 한다.
// 집터 맨 왼쪽 위의 좌표는 (0,0)이며 각 좌표에 대해 우리가 할 수 있는 작업은 다음 두 가지이다.
// 1. 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
// 2. 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
// (1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다.)
// 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다.
// 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있으며, 땅의 높이는 256블록을 초과하거나 음수가 될 수 없다.
// 작업에 걸리는 최소 시간과 작업 완료 후 땅의 높이를 출력하는 프로그램을 작성하시오.

// 입력: 첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)
//      둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다.
//      (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다.
//      땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.

// 출력: 첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오.
//      답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.


// 집터에서 높이가 가장 높은 값부터 가장 낮은 값까지 각각의 높이에 대해 걸리는 시간을 계산하고 (brute-force)
// 그 중에서 소요 시간이 가장 적으면서 높은 높이와 시간을 출력한다.


#include<stdio.h>
#include<stdlib.h>

#define HEIGHT_MAX 256
#define HEIGHT_MIN 0


int main()
{
    short m=0, n=0;
	short top=HEIGHT_MIN, bottom=HEIGHT_MAX;
	short height=0;
	short *land=0;
	int block=0, arr_len=0;
	int time=0;  // max=128,000,000
	int t=0, b=0;  // temp var of time, block
	
	scanf("%hd %hd %d", &n, &m, &block);
	arr_len = m*n;
	time = m*n*HEIGHT_MAX*2;
	
	if((land = (short *) calloc(arr_len, sizeof(short))) == NULL) {
		return -1;
	}
	
	for(int i=0; i<arr_len; i++) {
		scanf("%hd", &land[i]);
		if(land[i] > top) top=land[i];
		if(land[i] < bottom) bottom=land[i];
	}
	
	for(int h=top; h>=bottom; h--) {
		t = 0;
		b = block;
		for(int i=0; i<arr_len; i++) {
			if(land[i]>h) {
				t += 2*(land[i]-h);
				b += land[i]-h;
			} else if(land[i]<h) {
				t += (h-land[i]);
				b -= h-land[i];
			}
			if(b<0) {
				break;
			}
		}
		
		if(t<time && !(b<0)) {
			time = t;
			height = h;
		}
	}
	
	printf("%d %d\n", time, height);
	
	free(land);
	
    return 0;
}
