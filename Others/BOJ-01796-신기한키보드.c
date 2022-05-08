// BOJ-01796 / 신기한 키보드
// devgeon, 2022.05.08, C99
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


#include<stdio.h>
#define STR_LEN_MAX 50

int main()
{
	int idx=0, len=0;
	int count=0, cur=0;
	int count_temp=0, cur_temp=0;
	int finish=0, found=0, direction=0;
	char char_temp=0;
	char string[STR_LEN_MAX+1] = {0,};
	
	// input
	for(int i=0; i<STR_LEN_MAX+1; i++) {
		scanf("%c", &char_temp);
		if(char_temp<'a' || char_temp>'z') {
			len = i;
			break;
		}
		string[i] = char_temp;
	}
	
	if(len==1) {
		printf("1\n");
		return 0;
	}
	
	for(char c='a'; c<='z'; c++) {
		count_temp = 0;
		cur_temp = cur;
		found = 0;
		if(cur==0) {
			direction = 1;
			finish = 1;
		} else if(cur==len-1) {
			direction = -1;
			finish = 1;
		}
		else if(cur<(len+1)/2) {
			direction = -1;
			finish = 0;
		} else {
			direction = 1;
			finish = 0;
		}
		
		while(finish<2) {
			if(string[cur_temp]==c) {
				string[cur_temp] = ' ';
				count += count_temp+1;
				count_temp = 0;
				found = 1;
				cur = cur_temp;
			}
			count_temp++;
			cur_temp += direction;
			if(cur_temp==-1 || cur_temp==len) {
				direction *= -1;
				if(!found) {
					count_temp = 0;
					cur_temp = cur;
				} else {
					found = 0;
					cur_temp += direction*2;
				}
				finish++;
			}
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
