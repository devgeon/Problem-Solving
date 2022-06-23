// BOJ-10828 / 스택
// devgeon, 2022.06.23, C99
// https://www.acmicpc.net/problem/10828
 
// 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
// 명령은 총 다섯 가지이다.
// - push X: 정수 X를 스택에 넣는 연산이다.
// - pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// - size: 스택에 들어있는 정수의 개수를 출력한다.
// - empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// - top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

// 입력: 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
//      주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
// 출력: 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

// 연결리스트 형태로 스택을 구현하고, 스택에 접근할 때는 스택의 포인터를 인자로 받는 함수를 이용하도록 함.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CMD_LEN 5

typedef struct _Node {
	int num;
	struct _Node* left_link;
	struct _Node* right_link;
} Node;

typedef struct _Stack {
	int size;
	Node* bottom_addr;
	Node* top_addr;
} Stack;

Stack* createStack();
Stack* deleteStack(Stack* stack);
int push(Stack* stack, int n);
int pop(Stack* stack);
int size(Stack* stack);
int empty(Stack* stack);
int top(Stack* stack);
int input_cmd(char* cmd);

int main()
{
	int t=0, num=0;
	char cmd[CMD_LEN+1] = {0,};
	Stack* stack = 0;
	stack = createStack();
	
	scanf("%d\n", &t);
	for(int i=0; i<t; i++) {
		input_cmd(cmd);
		if(strncmp(cmd,"push",2)==0) {
			scanf("%d\n", &num);
			push(stack,num);
		} else if(strncmp(cmd,"pop",2)==0) {
			printf("%d\n", pop(stack));
		} else if(strncmp(cmd,"size",1)==0) {
			printf("%d\n", size(stack));
		} else if(strncmp(cmd,"empty",1)==0) {
			printf("%d\n", empty(stack));
		} else if(strncmp(cmd,"top",1)==0) {
			printf("%d\n", top(stack));
		}
	}
	
	stack = deleteStack(stack);
	return 0;
}

Stack* createStack()
{
	Stack* ptr = (Stack*) calloc(1, sizeof(Stack));
	if(ptr==NULL) {
		exit(1);
	}
	ptr->size = 0;
	ptr->bottom_addr = 0;
	ptr->top_addr = 0;
	return ptr;
}

Stack* deleteStack(Stack* stack)
{
	while(stack->size!=0) {
		pop(stack);
	}
	free(stack);
	return 0;
}

int push(Stack* stack, int n)
{
	Node* new_node = (Node*) calloc(1, sizeof(Node));
	if(new_node==NULL) {
		exit(1);
	}
	new_node->left_link = 0;
	new_node->right_link = 0;
	new_node->num = n;
	if(stack->size==0) {
		stack->bottom_addr = stack->top_addr = new_node;
	} else {
		stack->top_addr->right_link = new_node;
		new_node->left_link = stack->top_addr;
		stack->top_addr = new_node;
	}
	stack->size++;
	return n;
}

int pop(Stack* stack)
{
	int n=0;
	Node* temp = 0;
	if(stack->size==0) {
		return -1;
	}
	n = stack->top_addr->num;
	temp = stack->top_addr->left_link;
	free(stack->top_addr);
	stack->top_addr = temp;
	stack->size--;
	return n;
}

int size(Stack* stack)
{
	return stack->size;
}

int empty(Stack* stack)
{
	if(stack->size!=0) {
		return 0;
	} else {
		return 1;
	}
}

int top(Stack* stack)
{
	if(stack->size!=0) {
		return stack->top_addr->num;
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
