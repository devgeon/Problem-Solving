// BOJ-11655 / ROT13
// devgeon, 2022.05.24, C++17
// https://www.acmicpc.net/problem/11655
 
// ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.
// ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다.
// 문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 알파벳 대문자, 소문자, 공백, 숫자로만 이루어진 문자열 S가 주어진다. S의 길이는 100을 넘지 않는다.
// 출력: 첫째 줄에 S를 ROT13으로 암호화한 내용을 출력한다.


#include<iostream>

int main()
{
	char c=0;
	
	while((c = std::cin.get()) != '\n') {
		if(c>='A' && c<='M') {
			c += 13;
		} else if(c>='N' && c<='Z') {
			c -= 13;
		} else if(c>='a' && c<='m') {
			c += 13;
		} else if(c>='n' && c<='z') {
			c -= 13;
		}
		std::cout << c;
	}
	std::cout << std::endl;
	
	return 0;
}
