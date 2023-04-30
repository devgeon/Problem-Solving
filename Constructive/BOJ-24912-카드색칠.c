// BOJ-24912 / 카드 색칠
// devgeon, 2022.04.11, C99
// https://www.acmicpc.net/problem/24912
 
// 줄지어 놓인 카드를 다음 규칙에 따라 3가지 색으로 칠하려 한다.
// 1. 인접한 카드는 서로 다른 색으로 칠해야 한다.
// 2. 이미 색칠된 카드에 덧칠할 수 없다.
// 3. 카드의 순서를 바꿀 수 없다.
// 입력: 첫째 줄에 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000,000)
//      둘째 줄에 N개의 정수가 공백으로 구분되어 주어진다.
//      i번쩨 정수는 i번째 카드의 색을 나타낸다.
//      (0: 색칠되지 않음 / 1~3: 각각 빨강, 초록, 파랑)
// 출력: 한 줄에 N개의 정수를 공백으로 구분하여 출력한다.
//      각 정수는 1,2,3 중 하나여야 하며, 주어진 조건에 맞아야 한다.
//      가능한 방법이 여러 가지인 경우, 그중 아무거나 출력한다.
//      만약 모든 조건에 맞는 색칠이 불가능하다면, -1만 출력한다.


// 색칠할 수 없으면 -1만 출력해야 하는데 현재 코드는 출력하다가 -1을 출력함
// -> char배열에 공백 포함해서 출력값을 담아두거나, short배열에 숫자만 담아두고 출력하기
//    (메모리 제한이 512MB이고, N이 최대 1,000,000이므로 배열에 모두 담아도 공간은 충분함)

// 카드가 1장일 경우 정상적으로 동작하지 않음
// → 해당 상황에 대한 예외 추가하기


#include<stdio.h>
#include<stdlib.h>

int getColor(int n);

int main()
{
	int n=0, count=1;
	int card[3] = {0};
	char *result=0, *cur=0;
	
	scanf("%d", &n);
	
	if(n==1) {
		scanf("%d", &card[1]);
		if(card[1]!=0) {
			printf("%d", card[1]);
		} else {
			printf("%d", getColor(0));
		}
		return 0;
	}
	
	result = (char *) calloc(sizeof(char), 2*n);
	if(result==NULL) {
		printf("malloc failed");
		return 0;
	}
	cur = result;
	
	// color the first card
	scanf("%d %d", &card[1], &card[2]);
	if(card[1]!=0) {
		if(card[1]==card[2]) {
			printf("-1");
			return 0;
		}
	} else {
		card[1] = getColor(card[2]);
	}
	*cur++ = card[1]+'0';
	count++;
	
	// color the other cards
	while(count<n) {
		card[0] = card[1];
		card[1] = card[2];
		scanf("%d", &card[2]);
		
		if(card[1]!=0) {
			if(card[1]==card[2]) {
				printf("-1");
				return 0;
			}
		} else {
			if(card[2]==0) {
				card[1] = getColor(card[0]);
			} else {
				if(card[0]==card[2]) {
					card[1] = getColor(card[0]);
				} else {
					card[1] = 6 - card[0] - card[2];
				}
			}
		}
		*cur++ = ' ';
		*cur++ = card[1]+'0';
		count++;
	}
	
	// color the last card
	if(card[2]==0) {
		card[2] = getColor(card[1]);
	}
	*cur++ = ' ';
	*cur++ = card[2]+'0';
	*cur = '\0';
	
	printf("%s", result);
	
	free(result);
	result = cur = 0;
	
    return 0;
}

int getColor(int n) {
	int result=0;
	result = rand()%3+1;
	if(n!=0 && result==n) {
		result = (result+1)%3+1;
	}
	return result;
}
