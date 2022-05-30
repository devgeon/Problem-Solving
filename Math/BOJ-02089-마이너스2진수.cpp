// BOJ-02089 / -2진수
// devgeon, 2022.05.30, C++17
// https://www.acmicpc.net/problem/2089
 
// -2진법은 부호 없는 2진수로 나타낼 수 있다. (-2)^0=1, (-2)^1=-2, (-2)^2=4, (-2)^3=-8
// 1~9를 -2진법으로 나타내면 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001이 된다.
// 10진법의 수를 입력 받아서 -2진수를 출력하는 프로그램을 작성하시오.
// 입력: 첫 줄에 10진법으로 표현된 수 N이 주어진다.
// 출력: 첫째 줄에 -2진법 수를 출력한다.
// 제한: -2,000,000,000 ≤ N ≤ 2,000,000,000


#include<iostream>
#include<vector>

int main()
{
	int num_dec=0;
	bool num_mod=0;
	std::vector<bool> num_bin;
	
	std::cin >> num_dec;
	
	if(num_dec==0) {
		std::cout << "0" << std::endl;
		return 0;
	}
	while(num_dec != 1) {
		num_mod = ((num_dec % 2) << 1) >> 1;  // absolute value
		num_bin.push_back(num_mod);
		num_dec = (num_dec-num_mod) / (-2);
	}
	num_bin.push_back(num_dec);
	
	for(int i=num_bin.size()-1; i>=0; i--) {
		std::cout << num_bin[i];
	}
	std::cout << std::endl;
	
    return 0;
}
