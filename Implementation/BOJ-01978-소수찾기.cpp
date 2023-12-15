// BOJ-01978 / 소수 찾기
// devgeon, 2022.05.26, C++17
// https://www.acmicpc.net/problem/1978
 
// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
// 입력: 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다.
//      다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
// 출력: 주어진 수들 중 소수의 개수를 출력한다.


#include<iostream>
#include<array>

std::array<bool,1000> cache = {0,};

bool isPrimeNumber(int n);

int main()
{
	int n=0, count=0;
	int number=0;
	
	std::cin >> n;
	
	for(int i=0; i<n; i++) {
		std::cin >> number;
		if(isPrimeNumber(number)) {
			count++;
		}
	}
	
	std::cout << count << std::endl;
	
    return 0;
}

bool isPrimeNumber(int n)
{
	if(n==1) {
		return false;
	} else if(cache[n-1]) {
		return true;
	}
	for(int i=2; i*i<=n; i++) {
		if(n%i==0) {
			return false;
		}
	}
	cache[n-1] = true;
	return true;
}
