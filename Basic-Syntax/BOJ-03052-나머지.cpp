// BOJ-03052 / 나머지
// devgeon, 2022.05.21, C++17
// https://www.acmicpc.net/problem/3052
 
// 수 10개를 입력받은 뒤, 이를 42로 나눈 나머지에 대하여, 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.
// 출력: 첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.


#include<iostream>
#include<array>

int main()
{
	const int NUM_OF_INPUT = 10;
	const int DIVISOR = 42;
		
	int temp=0, count=0;
	std::array<int, DIVISOR> dist = {0,};  // distribution
	
	for(int i=0; i<NUM_OF_INPUT; i++) {
		std::cin >> temp;
		dist[temp%DIVISOR]++;
	}
	for(int i=0; i<DIVISOR; i++) {
		if(dist[i]!=0) {
			count++;
		}
	}
	
	std::cout << count << std::endl;
	
	return 0;
}
