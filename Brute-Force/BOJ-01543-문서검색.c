// BOJ-01543 / 문서 검색
// devgeon, 2022.05.08, C99
// https://www.acmicpc.net/problem/1543

// 어떤 단어가 총 몇 번 등장하는지 중복되지 않게 세는 프로그램을 작성하시오.
// 입력: 첫째 줄에 길이가 최대 2500인 문자열이 주어진다.
//      둘째 줄에 길이가 최대 50인 검색어가 주어진다.
//      문서와 단어는 알파벳 소문자와 공백으로 이루어져 있다.
// 출력: 첫째 줄에 중복되지 않게 최대 몇 번 등장하는지 출력한다.


#include<stdio.h>
#define WORD_LEN_MAX 50
#define DOC_LEN_MAX 2500

int input(char *string, int len);

int main()
{
	int count=0;
	int found=0;
	int word_len=0, doc_len=0;
	char word[WORD_LEN_MAX+1] = {0,};
	char doc[DOC_LEN_MAX+1] = {0,};
	
	doc_len = input(doc, DOC_LEN_MAX);
	word_len = input(word, WORD_LEN_MAX);
	
	for(int i=0; i<doc_len; i++) {
		if(doc[i]==word[0]) {
			found = 1;
			for(int j=1; j<word_len; j++) {
				if(doc[i+j]!=word[j]) {
					found = 0;
					break;
				}
			}
			if(found) {
				count++;
				for(int j=0; j<word_len; j++) {
					doc[i+j] = -1;
				}
			}
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}

int input(char *string, int len)
{
	for(int i=0; i<len+1; i++) {
		scanf("%c", &string[i]);
		if(string[i]=='\n' || string[i]==0) {
			return i;
		}
	}
	return -1;
}
