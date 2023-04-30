// BOJ-10845 / 큐
// devgeon, 2022.05.28, C99
// https://www.acmicpc.net/problem/10845
 
// 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
// 명령은 총 여섯 가지이다.
// - push X: 정수 X를 큐에 넣는 연산이다.
// - pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// - size: 큐에 들어있는 정수의 개수를 출력한다.
// - empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// - front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// - back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

// 입력: 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
//      주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
// 출력: 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

// 연결리스트 형태로 큐를 구현하고, 큐에 접근할 때는 큐의 포인터를 인자로 받는 함수를 이용하도록 함.
// 마지막 노드의 주소의 경우 자주 사용되므로 큐 구조체를 선언할 때 해당 멤버변수를 추가로 선언함.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CMD_LEN 5

typedef struct _Node {
	int num;
	struct _Node* next;
} Node;

typedef struct _Queue {
	int length;
	Node* first_addr;
	Node* last_addr;
} Queue;

Queue* createQueue();
Queue* deleteQueue(Queue* queue);
int push(Queue* queue, int n);
int pop(Queue* queue);
int size(Queue* queue);
int empty(Queue* queue);
int front(Queue* queue);
int back(Queue* queue);
int input_cmd(char* cmd);

int main()
{
	int t=0, num=0;
	char cmd[CMD_LEN+1] = {0,};
	Queue* queue = 0;
	queue = createQueue();
	
	scanf("%d\n", &t);
	for(int i=0; i<t; i++) {
		input_cmd(cmd);
		if(strncmp(cmd,"push",2)==0) {
			scanf("%d\n", &num);
			push(queue,num);
		} else if(strncmp(cmd,"pop",2)==0) {
			printf("%d\n", pop(queue));
		} else if(strncmp(cmd,"size",1)==0) {
			printf("%d\n", size(queue));
		} else if(strncmp(cmd,"empty",1)==0) {
			printf("%d\n", empty(queue));
		} else if(strncmp(cmd,"front",1)==0) {
			printf("%d\n", front(queue));
		} else if(strncmp(cmd,"back",1)==0) {
			printf("%d\n", back(queue));
		}
	}
	
	queue = deleteQueue(queue);
	return 0;
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

int push(Queue* queue, int n)
{
	Node* new_node = (Node*) calloc(1, sizeof(Node));
	if(new_node==NULL) {
		exit(1);
	}
	new_node->next = 0;
	new_node->num = n;
	if(queue->length==0) {
		queue->first_addr = queue->last_addr = new_node;
	} else {
		queue->last_addr->next = new_node;
		queue->last_addr = new_node;
	}
	queue->length++;
	return n;
}

int pop(Queue* queue)
{
	int n=0;
	Node* temp = 0;
	if(queue->length==0) {
		return -1;
	}
	n = queue->first_addr->num;
	temp = queue->first_addr->next;
	free(queue->first_addr);
	queue->first_addr = temp;
	queue->length--;
	return n;
}

int size(Queue* queue)
{
	return queue->length;
}

int empty(Queue* queue)
{
	if(queue->length!=0) {
		return 0;
	} else {
		return 1;
	}
}

int front(Queue* queue)
{
	if(queue->length!=0) {
		return queue->first_addr->num;
	} else {
		return -1;
	}
}

int back(Queue* queue)
{
	if(queue->length!=0) {
		return queue->last_addr->num;
	} else {
		return -1;
	}
}

int input_cmd(char* cmd)
{
	char c=0;
	for(int i=0; i<=CMD_LEN; i++) {
		c = getchar();
		if(c!='\n' && c!=' ') {
			cmd[i] = c;
		} else {
			cmd[i] = 0;
			return i;
		}
	}
	return -1;
}
