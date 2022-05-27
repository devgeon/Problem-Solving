// BOJ-01676 / 팩토리얼 0의 개수
// devgeon, 2022.05.27, C++17
// https://www.acmicpc.net/problem/1676
 
// 자연수 N이 주어지면 N!의 오른쪽 끝에 있는 0의 개수를 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)
// 출력: 첫째 줄에 구한 0의 개수를 출력한다.

// 알고리즘은 3474번 문제와 동일하다
// https://github.com/devgeon/Problem-Solving/blob/main/Math/BOJ-03474-교수가된현우.cpp


#include<iostream>

int main()
{
	int number=0, temp=0;
	int count_five=0;
	bool found_five=false;
	
	std::cin >> number;
	
	while(number>=2) {
		temp = number;
		do {
			found_five = false;
			if(temp%5==0) {
				temp /= 5;
				count_five++;
				found_five = true;
			}
		} while(found_five);
		number--;
	}
	
	std::cout << count_five << std::endl;
	
    return 0;
}
