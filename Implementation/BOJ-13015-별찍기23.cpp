// BOJ-13015 / 별 찍기 - 23
// devgeon, 2022.06.03, C++17
// https://www.acmicpc.net/problem/13015

// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
// 입력: 첫째 줄에 N(2 ≤ N ≤ 100)이 주어진다.
// 출력: 규칙대로 별을 출력한다.


#include<iostream>

using namespace std;

void print_n(char c, int n);

int main()
{
	int num=0, end=0;
	int indent=0, space=0;
	cin >> num;
	end = num*2-1;
	
	for(int i=0; i<end; i++) {
		if(i==0 || i==end-1) {
			print_n('*', num);
			print_n(' ', (num-1)*2-1);
			print_n('*', num);
		} else {
			if(i<num) {
				indent = i;
				if(i==num-1) {
					space = 0;
				} else {
					space = (num*2-3)-i*2;
				}
			} else {
				indent = (num*2-2)-i;
				space = 2*i-(num*2-1);
			}
			print_n(' ', indent);
			print_n('*', 1);
			print_n(' ', num-2);
			print_n('*', 1);
			print_n(' ', space);
			if(i!=num-1) print_n('*', 1);
			print_n(' ', num-2);
			print_n('*', 1);
		}
		cout << endl;
	}
	
    return 0;
}

void print_n(char c, int n)
{
	for(int i=0; i<n; i++) {
		cout << c;
	}
}
