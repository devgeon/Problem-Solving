// BOJ-10813 / 공 바꾸기
// devgeon, 2022.05.17, C99
// https://www.acmicpc.net/problem/10813
 
// N개의 상자에 1번부터 N번까지 번호가 붙어있고, 각 상자마다 상자와 같은 번호가 적힌 공이 1개씩 들어있다.
// 공을 바꿀 상자를 2개 선택하고 두 상자의 공을 서로 교환하는 과정을 M번 반복한 이후에 각 상자에 어떤 공이 들어있는지 구하는 프로그램을 작성하시오.

// 입력: 첫째 줄에 N (1 ≤ N ≤ 100)과 M (1 ≤ M ≤ 100)이 주어진다. 둘째 줄부터 M개의 줄에 걸쳐서 공을 교환할 방법이 주어진다.
//      각 방법은 두 정수 i j로 이루어져 있으며, i번 상자와 j번 상자에 들어있는 공을 교환한다는 뜻이다. (1 ≤ i ≤ j ≤ N)
// 출력: 1번 상자부터 N번 상자에 들어있는 공의 번호를 공백으로 구분해 출력한다.


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n=0, temp=0;
	int box_num=0;
	int sel1=0, sel2=0;
	int *boxes = 0;
	
	scanf("%d %d", &box_num, &n);
	
	boxes = (int*) calloc(box_num, sizeof(int));
	if(boxes==NULL) {
		exit(1);
	}
	for(int i=0; i<box_num; i++) {
		boxes[i] = i+1;
	}
	
	for(int i=0; i<n; i++) {
		scanf("%d %d", &sel1, &sel2);
		sel1--;
		sel2--;
		temp = boxes[sel1];
		boxes[sel1] = boxes[sel2];
		boxes[sel2] = temp;
	}
	
	for(int i=0; i<box_num; i++) {
		printf("%d", boxes[i]);
		if(i==box_num-1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	
    return 0;
}
