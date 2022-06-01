// BOJ-01796 / 신기한 키보드
// devgeon, 2022.05.10, C99
// https://www.acmicpc.net/problem/1796
 
// 문자열 S를 한 글자 씩 알파벳 순서대로 출력하려고 한다.
// 왼쪽방향키는 커서를 왼쪽으로 한 칸 이동시키며, 오른쪽방향키는 커서를 오른쪽으로 한 칸 이동시킨다.
// 엔터키를 입력하면 커서가 위치한 칸의 문자가 출력된다.
// 커서는 가장 왼쪽 문자에 위치해 있다.
// 문자열 S에 있는 모든 문자를 하나도 빠짐없이 알파벳 순서대로 출력하고자 할 때,
// 키의 입력을 최소화하는 프로그램을 작성하시오.

// 입력: 첫째 줄에 문자열 S가 주어진다.
//      문자열 S의 길이는 50보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.
// 출력: 문자열 S의 모든 문자를 알파벳 순서대로 출력하고자 할 때, 키를 누르는 횟수의 최솟값을 출력한다.

// 반례: caabcd는 17이 최소값인데 지금 알고리즘으로는 19가 나옴.
//      c를 입력할 때 b에서 끝부분으로 가까운 두 번째 c를 먼저하는 것보다
//      첫 번째 c를 먼저 입력하는 것이 키를 더 적게 누름.

// 수정사항: 다음 턴의 문자가 위치한 자리까지 이동하는 것도 계산하여 최솟값을 선택하도록 수정하였으나,
//         caabcd 같은 경우 b에서 우측 c자리로 이동하는 게 해당 턴에서는 값이 최소가 되기에
//         문제가 해결되지 않음.


#include<stdio.h>
#include<string.h>
#define STR_LEN_MAX 50

int input();
int calcDirection(int* cur, int len, int* direction, int* attempt, int* finish);
int countKeys(int* count, int* cur, char string[], int len, char c, int stop_1st_char);

int main()
{
	int len=0;
	int count=0, cur=0;
	char string[STR_LEN_MAX+1] = {0,};
	
	len = input(string);
	
	if(len==1) {
		printf("1\n");
		return 0;
	}
	
	for(char c='a'; c<='z'; c++) {
		countKeys(&count, &cur, string, len, c, 0);
	}
	
	printf("%d\n", count);
	
	return 0;
}

int input(char string[])
{
	int len=0;
	char char_temp=0;
	
	for(int i=0; i<STR_LEN_MAX+1; i++) {
		scanf("%c", &char_temp);
		if(char_temp<'a' || char_temp>'z') {
			len = i;
			break;
		}
		string[i] = char_temp;
	}
	return len;
}

int calcDirection(int* cur, int len, int* direction, int* attempt, int* finish)
{
	if(*cur==0) {
		*direction = 1;
		*attempt = 1;
		*finish = 1;
	} else if(*cur==len-1) {
		*direction = -1;
		*attempt = 1;
		*finish = 1;
	}
	else if(*cur<(len+1)/2) {
		*direction = -1 * (*attempt?-1:1);
		*finish = 0;
	} else {
		*direction = 1 * (*attempt?-1:1);
		*finish = 0;
	}
	return 0;
}

int countKeys(int* count, int* cur, char string[], int len, char c, int stop_1st_char)
{
	int attempt=0, finish=0, direction=0;
	int count_min[2]={0,}, cur_min[2]={0,};
	int count_temp=0, cur_temp=0;
	char string_temp[STR_LEN_MAX+1] = {0,};
	count_min[0] = count_min[1] = *count;
	cur_min[0] = cur_min[1] = *cur;

	while(attempt<2) {
		count_temp = 0;
		cur_temp = *cur;
		strcpy(string_temp, string);
		calcDirection(cur, len, &direction, &attempt, &finish);

		while(finish<2) {
			if(string_temp[cur_temp]==c) {
				count_min[attempt] += count_temp+1;
				cur_min[attempt] = cur_temp;
				if(!stop_1st_char) {
					string_temp[cur_temp] = ' ';
				} else {
					count_min[attempt]--;
					break;
				}
				count_temp = 0;
			}
			count_temp++;
			cur_temp += direction;
			if(cur_temp==-1 || cur_temp==len) {
				count_temp = 0;
				direction *= -1;
				cur_temp = cur_min[attempt];
				finish++;
			}
		}
		if(!stop_1st_char && count_min[1]!=*count && c!='z') {
			countKeys(&count_min[attempt], &cur_min[attempt], string_temp, len, c+1, 1);
		}
		attempt++;
	}

	strcpy(string, string_temp);
	if(count_min[0]==*count && count_min[1]!=*count) {
		*count = count_min[1];
		*cur = cur_min[1];
	} else if(count_min[0]!=*count && count_min[1]!=*count) {
		if(count_min[0]>=count_min[1]) {
			*count = count_min[1];
			*cur = cur_min[1];
		} else {
			*count = count_min[0];
			*cur = cur_min[0];
		}
	}
	
	return 0;
}
