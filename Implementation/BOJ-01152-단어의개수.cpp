// BOJ-01152 / 단어의 개수
// devgeon, 2022.06.03, C++17
// https://www.acmicpc.net/problem/1152
 
// 영어 대소문자와 공백으로 이루어진 문자열이 주어진다.
// 이 문자열에 몇 개의 단어가 있는지 구하는 프로그램을 작성하시오.
// 단, 한 단어가 여러 번 등장하면 등장한 횟수 만큼 모두 세어야 한다.
// 입력: 첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.
// 출력: 입력으로 주어진 숫자 N개의 합을 출력한다.


#include<iostream>

int main()
{
	char c=0;
	int len=0;
	int last_space=-1;
	int count_space=0;
	int ignore_space=0;
	int result=0;
	
	while(true) {
		c = std::cin.get();
		if(c==' ') {
			if(len==0) {
				ignore_space++;
			} else {
				last_space = len;
			}
			count_space++;
		} else if(c=='\n') {
			break;
		}
		len++;
	}
	
	if(last_space == len-1) {
		ignore_space++;
	}
	if(len==ignore_space) {
		result = 0;
	} else {
		result = count_space - ignore_space + 1;
	}
	
	std::cout << result << std::endl;
	
	return 0;
}
