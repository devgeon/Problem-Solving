// BOJ-02193 / 이친수
// devgeon, 2022.05.23, C++17
// https://www.acmicpc.net/problem/2193
 
// 0과 1로만 이루어진 수를 이진수라 한다. 이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 이들을 이친수(pinary number)라 한다.
// 이친수는 다음의 성질을 만족한다.
//  - 이친수는 0으로 시작하지 않는다.
//  - 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
// 예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.
// N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 N이 주어진다.
// 출력: 첫째 줄에 N자리 이친수의 개수를 출력한다.


#include<iostream>

long long combination(int n, int r);  // max -> combination(44,22) == 2104098963720

int main()
{
	int n=0;
	unsigned long long count=0;
	
	std::cin >> n;
	
	if(n==1) {
		count = 1;
	} else {
		int end = (n-1)/2;
		for(int i=0; i<=end; i++) {
			count += combination(n-1-i, i);
		}
	}
	
    std::cout << count << std::endl;
	
    return 0;
}

long long combination(int n, int r)
{
	unsigned long long result=1;
	int i=n, j=1;
	
	if(r==0)
		return 1;
	else if(r==1 || r==n-1)
		return n;
	while(true) {
		if(j<=r) {
			if(result%j==0) {
				result /= j;
				j++;
			}
		}
		if(i>n-r) {
			result *= i;
			i--;
		}
		if(i==n-r && j==r+1) {
			break;
		}
	}
	
	return result;
}
