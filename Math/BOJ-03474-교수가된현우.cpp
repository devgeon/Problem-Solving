// BOJ-03474 / 교수가 된 현우
// devgeon, 2022.05.27, C++17
// https://www.acmicpc.net/problem/3474
 
// 자연수 N이 주어지면 N!의 오른쪽 끝에 있는 0의 개수를 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 테스트 케이스의 개수 T가 주어지고, 이어서 T개의 줄에 정수 N이 주어진다. (1 ≤ N ≤ 1000000000)
// 출력: 각 줄마다 N!의 오른쪽 끝에 있는 0의 개수를 출력한다.


// 팩토리얼 계산 값 끝에 0이 오는 경우는 n부터 1까지 곱할 때 10이 얼마나 곱해지냐에 달려있으므로 각각의 수의 
// 소인수에 대하여 2와 5가 얼마나 포함되어 있는지를 세면 팩토리얼을 직접 구하지 않고도 0의 개수를 알 수 있다.
// 이때, 2 이상인 모든 자연수 n에 대하여 n~1 각각의 소인수에 포함된 5의 개수가 2보다 적기 때문에 5의 개수만 
// 구하여도 0의 개수를 알 수 있다.


#include<iostream>

int main()
{
	int n=0;
	int number=0, temp=0;
	int count_five=0;
	bool found_five=false;
	
	std::cin >> n;
	
	for(int i=0; i<n; i++) {
		std::cin >> number;
		count_five = 0;
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
	}
	
    return 0;
}
