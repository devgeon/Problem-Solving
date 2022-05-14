// BOJ-14397 / 해변
// devgeon, 2022.05.14, C99
// https://www.acmicpc.net/problem/14397
 
// 단위 정육각형으로 이루어진 지도가 주어졌을 때, 해변의 길이를 구하는 프로그램을 작성하시오.
// 해변은 정육각형의 변 중에서 한 쪽은 물인데, 한 쪽은 땅인 곳을 의미한다.

// 입력: 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 50)
//      둘째 줄부터 N개의 줄에 지도가 주어진다. '.'은 물, '#'은 땅이다.
// 출력: 첫째 줄에 해변의 길이를 출력한다.


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int width=0, height=0;
	int beach_count=0, d=0;
	char **map=0;
	
	scanf("%d %d\n", &height, &width);
	
	map = (char**) calloc(height, sizeof(char*));
	if(map == NULL) {
		exit(1);
	}
	for(int i=0; i<height; i++) {
		map[i] = (char*) calloc(width, sizeof(char));
		if(map[i] == NULL) {
			exit(1);
		}
	}
	
	for(int i=0, j=0; i<height;) {
		scanf("%c", &map[i][j]);
		if(map[i][j]=='.') {
			map[i][j] = 0;
		} else if(map[i][j]=='#') {
			map[i][j] = 1;
		} else {
			continue;
		}
		j++;
		if(j>=width) {
			j = 0;
			i++;
		}
	}
	
	for(int i=0, j=0; i<height;) {
		if(map[i][j]==1) {
			if(i>0) {
				if(i%2==0) d = -1;
				else d = 0;
				if(((i%2==0 && j>0) || i%2==1) && map[i-1][j+d]==0) beach_count++;  // top left
				if(((i%2==1 && j<width-1) || i%2==0) && map[i-1][j+d+1]==0) beach_count++;  // top right
			}
			if(j>0 && map[i][j-1]==0) beach_count++;  // left
			if(j<width-1 && map[i][j+1]==0) beach_count++;  // right
			if(i<height-1) {
				if(i%2==0) d = -1;
				else d = 0;
				if(((i%2==0 && j>0) || i%2==1) && map[i+1][j+d]==0) beach_count++;  // bottom left
				if(((i%2==1 && j<width-1) || i%2==0) && map[i+1][j+d+1]==0) beach_count++;  // bottom right
			}
		}
		j++;
		if(j>=width) {
			j = 0;
			i++;
		}
	}
	
	printf("%d\n", beach_count);
	
	for(int i=0; i<height; i++) {
		free(map[i]);
	}
	free(map);
	
	return 0;
}
