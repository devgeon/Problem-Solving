// BOJ-01254 / 팰린드롬 만들기
// devgeon, 2022.05.05, C99
// https://www.acmicpc.net/problem/1254
 
// 팰린드롬이란 앞에서부터 읽으나 뒤에서부터 읽으나 같은 문자열을 말한다.
// 주어진 문자열 S에 0개 이상의 문자를 가능한 적게 추가하여 팰린드롬을 만드려고 한다.
// 만들 수 있는 가장 짧은 팰린드롬의 길이를 출력하는 프로그램을 작성하시오.

// 입력: 첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 최대 50이다.

// 출력: 첫째 줄에 동호가 만들 수 있는 가장 짧은 팰린드롬의 길이를 출력한다.


// 고쳐야 할 점: 마지막 글자와 중복된 글자가 있으면 해당 글자를 새로 추가한 글자로 착각하여 그 앞에 추가하는 오류가 있음.


#include<stdio.h>
#include<string.h>
#define STR_LEN_MAX 50

int checkPalindrome(char* string, int len);
int insertChar(char* string, int len, int idx);

int main()
{
    int cur=0, len=0, temp=0;
	char string[STR_LEN_MAX*2+1] = {0,};
	
	for(int i=0; i<=STR_LEN_MAX; i++) {
		scanf("%c", &string[i]);
		if(string[i]<'a' || string[i]>'z') {
			len = i;
			break;
		}
	}
	
	while((temp = checkPalindrome(string, len)) != -1) {
		len = insertChar(string, len, cur);
	}
	
	printf("%d\n", len);
	return 0;
}

int checkPalindrome(char* string, int len)
{
	for(int i=0; i<(len+1)/2; i++) {
		if(string[i]!=string[len-i-1]) {
			return len-i-1;
		}
	}
	return -1;
}

int insertChar(char* string, int len, int idx)
{
	for(int i=len-1; i>idx; i--) {
		string[i+1] = string[i];
	}
	string[idx+1] = string[len-idx-1];
	return len+1;
}
