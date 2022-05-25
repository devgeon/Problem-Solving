// BOJ-01475 / 방 번호
// devgeon, 2022.05.25, C++17
// https://www.acmicpc.net/problem/1475
 
// 방 번호를 플라스틱 숫자를 이용하여 문에 붙이려고 할 때, 필요한 플라스틱 숫자 세트의 최솟값을 구하는 프로그램을 작성하시오.
// 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있으며, 6은 9를 뒤집어서 사용할 수 있고, 9는 6을 뒤집어서 사용할 수 있다.
// 입력: 첫째 줄에 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.
// 출력: 첫째 줄에 필요한 세트의 개수를 출력한다.


#include<iostream>
#include<array>

int main()
{
	int room_number=0;
	int num_of_set=0;
	std::array<int,10> distribution = {0,};
	
	std::cin >> room_number;
	
	if(room_number==0) {
		distribution[0]++;
	}
	while(room_number>0) {
		distribution[room_number%10]++;
		room_number/=10;
	}
	
	distribution[6] = distribution[9] = (distribution[6]+distribution[9])/2 + (distribution[6]+distribution[9])%2;
	
	for(int i=0; i<10; i++) {
		if(num_of_set < distribution[i]) {
			num_of_set = distribution[i];
		}
	}
	
    std::cout << num_of_set << std::endl;
	
    return 0;
}
