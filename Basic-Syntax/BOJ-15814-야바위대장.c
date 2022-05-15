// BOJ-15814 / 야바위 대장
// devgeon, 2022.05.15, C99
// https://www.acmicpc.net/problem/15814
 
// T번 동안 문자열 S의 A번째 위치에 있는 문자와 B번째 위치에 있는 문자를 바꾼 결과를 출력하는 프로그램을 작성하시오.
// 입력: 첫 번째 줄에 문자열 S가 주어지고 두 번째 줄에 T가 주어진다. 문자열 S의 길이는 100보다 작거나 같은 자연수이며,
//      알파벳 대소문자와 하이픈(-)으로만 이루어져 있다. T는 50보다 작거나 같은 자연수이다.
//      그 다음 T개의 줄에 걸쳐 A와 B가 주어진다. A와 B는 문자열의 길이보다 작은 음이 아닌 정수이며, 문자열의 맨 처음 글자는 0번째 글자이다.
// 출력: 바뀐 문자열의 결과를 출력한다.


#include<stdio.h>
#define STR_LEN_MAX 100

int main()
{
	int n=0, idx1=0, idx2=0;
	char temp=0;
	char string[STR_LEN_MAX+1] = {0,};
	
	for(int i=0; i<STR_LEN_MAX; i++) {
		scanf("%c", &string[i]);
		if((string[i]<'A' || string[i]>'z') && string[i]!='-') {
			break;
		}
	}
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d %d", &idx1, &idx2);
		temp = string[idx1];
		string[idx1] = string[idx2];
		string[idx2] = temp;
	}
	
	printf("%s\n", string);
	
	return 0;
}
