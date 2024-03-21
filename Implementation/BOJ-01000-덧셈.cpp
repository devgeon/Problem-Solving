// BOJ-01000 / A+B
// devgeon, 2022.06.03, C++17
// https://www.acmicpc.net/problem/1000
 
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)
// 출력: 첫째 줄에 A+B를 출력한다.


#include<iostream>

int main()
{
	char num1=0, num2=0;
	
	std::cin >> num1 >> num2;
	std::cout << num1+num2-('0'*2) << std::endl;
	
	return 0;
}
