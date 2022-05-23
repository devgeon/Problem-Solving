// BOJ-01546 / 평균
// devgeon, 2022.05.23, C++17
// https://www.acmicpc.net/problem/1546
 
// 시험 점수 중에 최댓값을 M이라고 할 때, 모든 점수를 (점수)/M*100으로 고쳐서 새로 평균을 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 시험 본 과목의 개수 N이 주어진다. 이 값은 1000보다 작거나 같다.
//      둘째 줄에 현재 성적이 주어진다. 이 값은 100보다 작거나 같은 음이 아닌 정수이고, 적어도 하나의 값은 0보다 크다.
// 출력: 첫째 줄에 새로운 평균을 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10-2 이하이면 정답이다.

// 각각의 점수에 곱하고 나누어서 평균을 구하나, 평균을 구해서 곱하고 나누나 결과는 동일함을 이용하여 풀기


#include<iostream>

int main()
{
	int n=0, temp=0;
	int max=0, sum=0;
	float mean=0;
	
	std::cin >> n;
	
	for(int i=0; i<n; i++) {
		std::cin >> temp;
		sum += temp;
		if(temp>max) {
			max = temp;
		}
	}
	
	mean = (sum * 100 / (float)n) / max;
	
    std::cout << mean << std::endl;
	
    return 0;
}
