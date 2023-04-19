// BOJ-07576 / 토마토
// devgeon, 2022.05.29, C99
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

// TLE -> BFS로 개선함.
// MLE -> Queue에 이미 포함된 항목이 중복되어 들어가지 않도록 개선함.


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct _Coord {
	short r;  // row
	short c;  // col
} Coord;

typedef struct _Node {
	struct _Coord coord;
	struct _Node* next;
} Node;

typedef struct _Queue {
	int length;
	Node* first_addr;
	Node* last_addr;
} Queue;

typedef struct _FruitStorage {
		short width;
		short height;
		char **boxes;
	} FruitStorage;

Queue* createQueue();
Queue* deleteQueue(Queue* queue);
Coord push(Queue* queue, Coord coord);
Coord pop(Queue* queue);

int tomorrow(FruitStorage* storage, Queue* queue, int day);


int main()
{
	int day=0, temp=0;
	Coord coord = {0,};
	FruitStorage storage = {0,};
	Queue* queue = createQueue();
	
	scanf("%hd %hd", &storage.width, &storage.height);
	
	storage.boxes = (char**) calloc(storage.width*storage.height, sizeof(char*));
	if(!storage.boxes) {
		printf("calloc error");
		exit(1);
	}
	for(int i=0; i<storage.height; i++) {
		storage.boxes[i] = (char*) calloc(storage.width, sizeof(char));
		if(!storage.boxes[i]) {
			printf("calloc error");
			exit(1);
		}
	}
	
	for(int i=0; i<storage.height; i++) {
		for(int j=0; j<storage.width; j++) {
			scanf("%hhd", &storage.boxes[i][j]);
			if(storage.boxes[i][j]==1) {
				coord.r = i;
				coord.c = j;
				push(queue, coord);
			}
		}
	}
	
	while(queue->length != 0) {
		day = tomorrow(&storage, queue, day);
	}
	day--;
	for(int i=0; i<storage.height; i++) {
		for(int j=0; j<storage.width; j++) {
			if(storage.boxes[i][j]==0) {
				day = -1;
				break;
			}
		}
		if(day==-1) {
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


int tomorrow(FruitStorage* storage, Queue* queue, int day)
{
	int end = queue->length;
	Coord coord = {0,};
	Coord temp = {0,};
	for(int i=0; i<end; i++) {
		coord = pop(queue);
		storage->boxes[coord.r][coord.c] = 1;
		if(coord.r > 0) {
			temp.r = coord.r-1;
			temp.c = coord.c;
			if(storage->boxes[temp.r][temp.c]==0) {
				storage->boxes[temp.r][temp.c] = 2;
				push(queue, temp);
			}
		}
		if(coord.r < storage->height-1) {
			temp.r = coord.r+1;
			temp.c = coord.c;
			if(storage->boxes[temp.r][temp.c]==0) {
				storage->boxes[temp.r][temp.c] = 2;
				push(queue, temp);
			}
		}
		if(coord.c > 0) {
			temp.r = coord.r;
			temp.c = coord.c-1;
			if(storage->boxes[temp.r][temp.c]==0) {
				storage->boxes[temp.r][temp.c] = 2;
				push(queue, temp);
			}
		}
		if(coord.c < storage->width-1) {
			temp.r = coord.r;
			temp.c = coord.c+1;
			if(storage->boxes[temp.r][temp.c]==0) {
				storage->boxes[temp.r][temp.c] = 2;
				push(queue, temp);
			}
		}
	}
	return ++day;
}


Queue* createQueue()
{
	Queue* ptr = (Queue*) calloc(1, sizeof(Queue));
	if(ptr==NULL) {
		exit(1);
	}
	ptr->length = 0;
	ptr->first_addr = 0;
	ptr->last_addr = 0;
	return ptr;
}

Queue* deleteQueue(Queue* queue)
{
	while(queue->length!=0) {
		pop(queue);
	}
	free(queue);
	return 0;
}

Coord push(Queue* queue, Coord coord)
{
	if(queue->length == INT_MAX) {
		exit(1);
	}
	Node* new_node = (Node*) calloc(1, sizeof(Node));
	if(new_node==NULL) {
		exit(1);
	}
	new_node->next = 0;
	new_node->coord = coord;
	if(queue->length==0) {
		queue->first_addr = queue->last_addr = new_node;
	} else {
		queue->last_addr->next = new_node;
		queue->last_addr = new_node;
	}
	queue->length++;
	return coord;
}

Coord pop(Queue* queue)
{
	Coord coord={0,};
	Node* temp = 0;
	if(queue->length==0) {
		coord.r = coord.c = -1;
		return coord;
	}
	coord = queue->first_addr->coord;
	temp = queue->first_addr->next;
	free(queue->first_addr);
	queue->first_addr = temp;
	queue->length--;
	return coord;
}
