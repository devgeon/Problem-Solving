// BOJ-01914 / 하노이 탑
// devgeon, 2022.05.31, C++17
// https://www.acmicpc.net/problem/1914

// 세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다.
// 다음 규칙에 따라 모든 원판을 첫 번째 장대에서 세 번째 장대로 옮기는데 필요한 이동 순서를 출력하는 프로그램을 작성하시오.
// (단, 이동 횟수는 최소가 되어야 한다.)
// - 한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
// - 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
// 입력: 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 100)이 주어진다.
// 출력: 첫째 줄에 옮긴 횟수 K를 출력한다. N이 20 이하인 입력에 대해서는 두 번째 줄부터 수행 과정을 출력한다.
//      두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 
//      B번째 탑의 가장 위로 옮긴다는 뜻이다. N이 20보다 큰 경우에는 과정은 출력할 필요가 없다.


#include<iostream>
#include<string>
#include<array>

const int NUM_LEN = 32;
std::string out_buf = "";

void hanoi(int num, int start, int end);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int num=0;
	char carry=0;
	long long count=0;
	std::array<int,NUM_LEN> count_big;
	for(int i=0; i<NUM_LEN; i++) {
		count_big[i] = -1;
	}
	
	std::cin >> num;
	
	if(num < 63) {
		count = (((long long) 2) << (num-1)) - 1;
		std::cout << count << std::endl;
		if(num <= 20) {
			hanoi(num,1,3);
		}
		std::cout << out_buf;
	} else {
		count = ((long long) 2) << (62-1);
		for(int i=NUM_LEN-1; i>=0; i--) {
			count_big[i] = count % 10;
			count /= 10;
			if(count==0) {
				break;
			}
		}
		if(count>0) {
			exit(1);  // overflow
		}
		for(int i=63; i<=num; i++) {
			carry = 0;
			for(int j=NUM_LEN-1; j>=0; j--) {
				if(count_big[j]<0) {
					if(carry==1) {
						if(j==0) {
							exit(1);  // overflow
						} else {
							count_big[j] = 1;
						}
					}
					break;
				}
				count_big[j] *= 2;
				if(carry==1) {
					count_big[j] += carry;
					carry = 0;
				}
				if(count_big[j]>=10) {
					count_big[j] %= 10;
					if(j==0) {
						exit(1);  // overflow
					} else {
						carry = 1;
					}
				}
			}
		}
		count_big[NUM_LEN-1]--;  // count_big[NUM_LEN-1] == 2 or 4 or 8 or 6
		for(int i=0; i<NUM_LEN; i++) {
			if(count_big[i]<0) {
				continue;
			}
			std::cout << count_big[i];
		}
		std::cout << std::endl;
	}
	
    return 0;
}

void hanoi(int num, int start, int end)
{
	if(num > 1) {
		hanoi(num-1, start, 6-start-end);
		out_buf += std::to_string(start) + " " + std::to_string(end) + "\n";
		hanoi(num-1, 6-start-end, end);
	} else {
		out_buf += std::to_string(start) + " " + std::to_string(end) + "\n";
	}
}
