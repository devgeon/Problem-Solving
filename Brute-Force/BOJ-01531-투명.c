// BOJ-01531 / 투명
// devgeon, 2022.05.11, C99
// https://www.acmicpc.net/problem/1531
 
// 100x100 크기의 그림을 N개의 반투명한 종이로 가릴 때, M개 이하의 종이가 올려져 있는 부분은 보이게 된다.
// N개의 반투명한 종이가 놓일 왼쪽 아래 모서리 좌표와 오른쪽 위 모서리 좌표가 입력으로 주어질 때,
// 가려져 보이지 않는 영역의 수를 세는 프로그램을 작성하시오.
// (종이가 가리는 영역에는 두 모서리의 좌표도 포함된다)

// 입력: 첫째 줄에 N과 M이 주어진다. N과 M은 각각 0 이상, 50 이하이다.
//      둘째 줄부터 N개의 줄에 종이의 좌표가 주어진다. 좌하단 모서리 x,y좌표, 우상단 모서리 x,y좌표 순으로 주어진다.
//      모든 좌표는 100 이하의 자연수이다.
// 출력: 첫째 줄에 정답을 출력한다.


#include<stdio.h>
#define ROW 100
#define COL 100

int main()
{
	int n=0, clear=0, count=0;
	int x1=0, y1=0, x2=0, y2=0;
	char drawing[ROW][COL] = {0,};
	
	scanf("%d %d", &n, &clear);
	
	for(int i=0; i<n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--; y1--; x2--; y2--;
		for(int x=x1; x<=x2; x++) {
			for(int y=y1; y<=y2; y++) {
				drawing[x][y]++;
			}
		}
	}
	
	for(int x=0; x<ROW; x++) {
		for(int y=0; y<COL; y++) {
			if(drawing[x][y]>clear) {
				count++;
			}
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
