// BOJ-01059 / 좋은 구간
// devgeon, 2022.05.22, C++17
// https://www.acmicpc.net/problem/1059
 
// 정수 집합 S가 주어졌을때, 다음 조건을 만족하는 구간 [A, B]를 좋은 구간이라고 한다.
//  - A와 B는 양의 정수이고, A < B를 만족한다.
//  - A ≤ x ≤ B를 만족하는 모든 정수 x가 집합 S에 속하지 않는다.
// 집합 S와 n이 주어졌을 때, n을 포함하는 좋은 구간의 개수를 구하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 집합 S의 크기 L이 주어진다. 둘째 줄에는 집합에 포함된 정수가 주어진다. 셋째 줄에는 n이 주어진다.
// 출력: 첫째 줄에 n을 포함하는 좋은 구간의 개수를 출력한다.
// 제한: 1 ≤ L ≤ 50
//      집합 S에는 중복되는 정수가 없다.
//      집합 S에 포함된 모든 정수는 1보다 크거나 같고, 1,000보다 작거나 같다.
//      1 ≤ n ≤ (집합 S에서 가장 큰 정수)


#include<iostream>
#include<vector>

const int NUM_MAX = 1000;

void selectionSort(std::vector<int>& numbers);

int main()
{
	int n=0, number=0;
	int large=0, small=0;
	int temp=0;
	std::cin >> n;
	std::vector<int> numbers;
	
	for(int i=0; i<n; i++) {
		std::cin >> temp;
		numbers.push_back(temp);
	}
	
	std::cin >> number;
	for(int i=0; i<n; i++) {
		if(numbers[i]==number) {
			std::cout << 0 << std::endl;
			return 0;
		}
	}
	
	selectionSort(numbers);
	
	for(int i=0; i<n; i++) {
		if(numbers[i]<number) {
			small = numbers[i];
		} else if(numbers[i]>number && large==0) {
			large = numbers[i];
			break;
		}
	}
	small = number - small - 1;
	large = large - number - 1;
	
	if(large+small==0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	
    std::cout << ((small * (large + 1)) + large) << std::endl;
    return 0;
}

void selectionSort(std::vector<int>& numbers)
{
	int min = NUM_MAX+1;
	int min_idx = 0;
	int temp = 0;
	int size = numbers.size();
	
	for(int sorted=0; sorted<size; sorted++) {
		for(int i=sorted; i<size; i++) {
			if(numbers[i] < min) {
				min = numbers[i];
				min_idx = i;
			}
		}
		temp = numbers[sorted];
		numbers[sorted] = numbers[min_idx];
		numbers[min_idx] = temp;
		min = NUM_MAX+1;
	}
}
