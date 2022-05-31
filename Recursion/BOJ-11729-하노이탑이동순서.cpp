// BOJ-11729 / 하노이 탑 이동 순서
// devgeon, 2022.05.31, C++17
// https://www.acmicpc.net/problem/11729

// 세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다.
// 다음 규칙에 따라 모든 원판을 첫 번째 장대에서 세 번째 장대로 옮기는데 필요한 이동 순서를 출력하는 프로그램을 작성하시오.
// (단, 이동 횟수는 최소가 되어야 한다.)
// - 한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
// - 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
// 입력: 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.
// 출력: 첫째 줄에 옮긴 횟수 K를 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력한다.
//      이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.


#include<iostream>

void hanoi(int num, int start, int end);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int num=0;
	int count=0;
	
	std::cin >> num;
	
	count = (2 << (num-1)) - 1;
	std::cout << count << std::endl;
	hanoi(num,1,3);
	
    return 0;
}

void hanoi(int num, int start, int end)
{
	if(num > 1) {
		hanoi(num-1, start, 6-start-end);
		std::cout << start << " " << end << "\n";
		hanoi(num-1, 6-start-end, end);
	} else {
		std::cout << start << " " << end << "\n";
	}
}
