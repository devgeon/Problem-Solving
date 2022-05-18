// BOJ-08958 / OX퀴즈
// devgeon, 2022.05.18, C++17
// https://www.acmicpc.net/problem/8958
 
// "OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다.
// 문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 예를 들어, 10번 문제의 점수는 3이 된다.
// OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고,
//      길이가 0보다 크고 80보다 작은 문자열이 주어진다. 문자열은 O와 X만으로 이루어져 있다.
// 출력: 각 테스트 케이스마다 점수를 출력한다.


#include<iostream>

using std::cin, std::cout, std::endl;

int main()
{
	int n=0;
	char temp=0;
	int score=0, bonus=1;
	
	cin >> n;
	cin.get();  // remove "\n" from buffer
	
	for(int i=0; i<n; i++) {
		while(true) {
			temp = cin.get();
			if(temp=='O') {
				score += bonus;
				bonus++;
			} else if(temp=='X') {
				bonus = 1;
			} else {
				cout << score << endl;
				score = 0;
				bonus = 1;
				break;
			}
		}
	}
	
    return 0;
}
