// BOJ-15813 / 너의 이름은 몇 점이니?
// devgeon, 2022.06.02, C++17
// https://www.acmicpc.net/problem/15813
 
// 알파벳 A부터 Z까지 각각 순서대로 1점부터 26점까지 점수가 있고,
// 이를 토대로 이름에 들어가는 모든 알파벳의 점수를 합한 것을 "이름점수"라고 한다.
// 주어진 이름에 대한 "이름점수"를 출력하는 프로그램을 작성하시오.
// 입력: 첫 번째 줄에 이름의 길이가 주어진다. 길이는 100자 이하이다.
//      두 번째 줄에 이름이 띄어쓰기 없이 대문자로 주어진다.
// 출력: 주어진 이름에 대한 "이름점수"를 출력한다.


#include<iostream>

int main()
{
	int n=0, score=0;
	char temp = 0;
	
	std::cin >> n;
	std::cin.get();  // remove "\n" from buffer
	
	for(int i=0; i<n; i++) {
		temp = std::cin.get();
		score += temp - 'A' + 1;
	}
	
	std::cout << score << std::endl;
	
	return 0;
}
