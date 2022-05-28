// BOJ-07576 / 토마토
// devgeon, 2022.05.21, C99
// https://www.acmicpc.net/problem/7576
 
// 토마토를 보관하는 가로 M, 세로 N 크기의 창고에 잘 익은 토마토와 익지 않은 토마토가 일부 칸은 비워두고 랜덤하게 보관되어 있다.
// 보관 후 하루가 지나면 잘 익은 토마토와 인접한 위치에 있는(=왼쪽, 오른쪽, 앞, 뒤에 위치한) 익지 않은 토마토가 익게 된다.
// 토마토가 혼자 저절로 익는 경우는 없다고 할 때, 창고에 보관된 토마토들이 다 익는데 걸리는 최소 일수를 구하는 프로그램을 작성하시오.

// 입력: 첫째 줄에 두 정수 M과 N이 주어진다. (2 ≤ M,N ≤ 1,000)
//      둘째 줄부터 N개의 줄에 토마토의 정보가 한 줄에 M개씩 주어진다.
//      정수 1은 잘 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 비어있는 칸을 나타낸다.
//      토마토가 하나 이상 보관된 경우만 입력으로 주어진다.
// 출력: 토마토가 모두 익을 때까지의 최소 날짜를 출력한다.
//      만약, 저장될 때부터 모든 토마토가 익어있는 상태라면 0을 출력하고, 토마토가 모두 익지 못하는 상황이면 -1을 출력한다.


#include<stdio.h>
#include<stdlib.h>

typedef struct _FruitStorage {
		int width;
		int height;
		int **boxes;
		int fruits;
		int ripe_fruits;
	} FruitStorage;

int tomorrow(FruitStorage* storage, int day);

int main()
{
	int day=0, temp=0;
	FruitStorage storage = {0,};
	
	scanf("%d %d", &storage.width, &storage.height);
	
	storage.boxes = (int**) calloc(storage.width*storage.height, sizeof(int*));
	if(!storage.boxes) {
		printf("calloc error");
		exit(1);
	}
	for(int i=0; i<storage.height; i++) {
		storage.boxes[i] = (int*) calloc(storage.width, sizeof(int));
		if(!storage.boxes[i]) {
			printf("calloc error");
			exit(1);
		}
	}
	
	for(int i=0; i<storage.height; i++) {
		for(int j=0; j<storage.width; j++) {
			scanf("%d", &storage.boxes[i][j]);
			if(storage.boxes[i][j]==1) {
				storage.ripe_fruits++;
			} else if(storage.boxes[i][j]==0) {
				storage.fruits++;
			}
		}
	}
	storage.fruits += storage.ripe_fruits;
	
	while(storage.fruits != storage.ripe_fruits) {
		temp = storage.ripe_fruits;
		day = tomorrow(&storage, day);
		if(temp == storage.ripe_fruits) {
			day = -1;
			break;
		}
	}
	
	printf("%d\n", day);
	
	for(int i=0; i<storage.height; i++) {
		free(storage.boxes[i]);
		storage.boxes[i] = 0;
	}
	free(storage.boxes);
	storage.boxes = 0;
	
	return 0;
}

int tomorrow(FruitStorage* storage, int day)
{
	for(int i=0; i<storage->height; i++) {
		for(int j=0; j<storage->width; j++) {
			if(storage->boxes[i][j]==1 || storage->boxes[i][j]==day+1) {
				if(storage->boxes[i][j]!=1) {
					storage->boxes[i][j] = 1;
				}
				if(i>0 && storage->boxes[i-1][j]==0) {
					storage->boxes[i-1][j] = day+2;
					storage->ripe_fruits++;
				}
				if(i<storage->height-1 && storage->boxes[i+1][j]==0) {
					storage->boxes[i+1][j] = day+2;
					storage->ripe_fruits++;
				}
				if(j>0 && storage->boxes[i][j-1]==0) {
					storage->boxes[i][j-1] = day+2;
					storage->ripe_fruits++;
				}
				if(j<storage->width-1 && storage->boxes[i][j+1]==0) {
					storage->boxes[i][j+1] = day+2;
					storage->ripe_fruits++;
				}
			}
		}
	}
	return ++day;
}
