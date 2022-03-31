// BOJ-10926-??!.c
// devgeon, 2022.03.31
// https://www.acmicpc.net/problem/10926
 
// joonas라는 아이디가 이미 존재할 경우 ??!를 붙여 놀람을 표현하는 프로그램을 작성하시오
// -> 다른 아이디여도 뒤에 ??!를 붙여야 정답으로 인정된다
// 입력: 이미 존재하는 알파벳 소문자로만 이루어진 50자 이하의 아이디가 주어진다
// 출력: 아이디 뒤에 ??!를 붙여 놀람을 출력한다

#include<stdio.h>
#include<string.h>

#define len 51

int main()
{
	char id[len+3] = {0};
	scanf("%s", id);
	// if(strcmp("joonas",id)==0) {
		strcat(id,"\?\?!");  // trigraph, "??!" == "|"
		printf("%s", id);
	// }
    return 0;
}
