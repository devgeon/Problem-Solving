// BOJ-01032 / 명령 프롬프트
// devgeon, 2022.05.12, C99
// https://www.acmicpc.net/problem/1032
 
// 명령 프롬프트에 "dir 패턴"과 같이 입력하면 패턴에 맞는 파일만 검색 결과로 나온다.
// 패턴에는 알파벳과 '.' 그리고 '?'만 넣을 수 있다. '?' 자리에는 모든 글자가 매칭된다.
// 파일 이름의 길이는 모두 같으며, 가능하면 '?'를 최대한 적게 사용해야 한다.
// 검색 결과에 나온 파일만 보고 패턴을 찾는 프로그램을 작성하시오.

// 입력: 첫째 줄에 파일 이름의 개수 N이 주어진다. 둘째 줄부터 N개의 줄에는 파일 이름이 주어진다.
//      N은 50보다 작거나 같은 자연수이고, 파일 이름의 길이는 최대 50이다.
//      파일이름은 알파벳 소문자와 '.' 로만 이루어져 있다.
// 출력: 첫째 줄에 패턴을 출력한다.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_NAME_LIMIT 50

int main()
{
	int n=0, len=0;
	char **file_names=0;
	char *pattern=0;
	
	scanf("%d\n", &n);
	
	pattern = (char*) calloc(FILE_NAME_LIMIT+1, sizeof(char));
	if(pattern == NULL) {
		exit(1);
	}
	
	for(int i=0; i<=FILE_NAME_LIMIT; i++) {
		scanf("%c", &pattern[i]);
		if((pattern[i]<'A' || pattern[i]>'z') && pattern[i]!='.') {
			pattern[i] = 0;
			len = i;
			break;
		}
	}
	
	file_names = (char**) calloc(n, sizeof(char*));
	if(file_names == NULL) {
		exit(1);
	}
	for(int i=0; i<n; i++) {
		file_names[i] = (char*) calloc(len+1, sizeof(char));
		if(file_names[i] == NULL) {
			exit(1);
		}
	}
	
	strncpy(file_names[0], pattern, len);
	free(pattern);
	
	pattern = (char*) calloc(len+1, sizeof(char));
	if(pattern == NULL) {
		exit(1);
	}
	
	for(int i=1; i<n; i++) {
		for(int j=0; j<len+1; j++) {
			scanf("%c", &file_names[i][j]);
			if((file_names[i][j]<'A' || file_names[i][j]>'z') && file_names[i][j]!='.') {
				file_names[i][j] = 0;
				break;
			}
		}
	}
	
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<len; j++) {
			if(file_names[i][j]!=file_names[i+1][j]) {
				pattern[j] = '?'; 
			} else if(pattern[j]==0) {
				pattern[j] = file_names[i][j];
			}
		}
	}
	
	if(n==1) {
		printf("%s\n", file_names[0]);
	} else {
		printf("%s\n", pattern);
	}
	
	for(int i=0; i<n; i++) {
		free(file_names[i]);
	}
	free(file_names);
	free(pattern);
	
	return 0;
}
