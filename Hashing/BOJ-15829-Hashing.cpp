// BOJ-15829 / Hashing
// devgeon, 2022.06.01, C++17
// https://www.acmicpc.net/problem/15829
 
// 해시 함수는 임의의 길이의 입력을 받아서 고정된 길이의 출력을 내보내는 함수이다.
// 해시 충돌은 입력이 서로 다름에도 해시 값이 동일한 경우를 말한다.
// 영문 소문자로만 구성된 문자열을 a=1, b=2, c=3, ... , z=26으로 치환하여 수열로 만들었을 때,
// 각 항의 번호에 해당하는 만큼 적당한 숫자 r을 거듭제곱한 값을 각 항에 곱해주고, 이를 모두 합하여 
// 적당히 큰 수 M으로 나눈 나머지를 출력하는 식으로 해시 함수를 만들 수 있다. (수식은 문제 링크 참고)
// r과 M은 서로소인 숫자로 정하는 것이 일반적이다.
// r=31, M=1234567891 로 할 때, 입력으로 들어온 문자열의 해시 값을 계산하는 프로그램을 작성하시오.

// 입력: 첫 줄에는 문자열의 길이 L이 들어온다. 둘째 줄에는 영문 소문자로만 이루어진 문자열이 들어온다.
// 출력: 문제에서 주어진 해시함수와 입력으로 주어진 문자열을 사용해 계산한 해시 값을 정수로 출력한다.

// Modular Distributive Properties
// (a±b)%c = ((a%c)±(b%c))%c
// (a×b)%c = ((a%c)×(b%c))%c


#include<iostream>

const int R = 31;
const long long M = 1234567891;

int main()
{
	int n=0;
	long long r=0, result=0;
	char c=0;
	
	std::cin >> n;
	std::cin.get();  // remove '\n'
	
	for(int i=0; i<n; i++) {
		c = std::cin.get();
		c = c-'a'+1;
		if(r==0) {
			r = 1;
		} else {
			r *= R;
			if(r > M) {
				r %= M;
			}
		}
		result += ((long long)c)*r;
		if(result > M) {
			result %= M;
		}
	}
	
	std::cout << result << std::endl;
	
    return 0;
}
