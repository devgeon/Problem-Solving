// BOJ-01914 / 하노이 탑
// devgeon, 2022.06.16, C++17
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

using namespace std;

class BigInt {
private:
	const int NUM_LEN = 32;
	int* big_int;
public:
	BigInt();
	~BigInt();
	void setNumber(long long n);
	void resetNumber();
	void printNumber();
	void multiplyNumber(short n);
	void addNumber(short n);
	void subtractNumber(short n);
};

void hanoi(int num, int start, int end, string& out_buf);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int num=0;
	long long count=0;
	string out_buf = "";
	BigInt big_num;
	
	cin >> num;
	
	if(num < 63) {
		count = (((long long) 2) << (num-1)) - 1;
		cout << count << endl;
		if(num <= 20) {
			hanoi(num,1,3,out_buf);
		}
		cout << out_buf;
	} else {
		try {
			count = ((long long) 2) << (62-1);
			big_num.setNumber(count);
			for(int i=63; i<=num; i++) {
				big_num.multiplyNumber(2);
			}
			big_num.subtractNumber(1);
			big_num.printNumber();
		} catch(const string error_msg) {
			cout << "Error: " << error_msg << endl;
			exit(1);
		}
	}
	
    return 0;
}


void hanoi(int num, int start, int end, string& out_buf)
{
	if(num > 1) {
		hanoi(num-1, start, 6-start-end, out_buf);
		out_buf += to_string(start) + " " + to_string(end) + "\n";
		hanoi(num-1, 6-start-end, end, out_buf);
	} else {
		out_buf += to_string(start) + " " + to_string(end) + "\n";
	}
}

BigInt::BigInt() {
	big_int = new int[NUM_LEN];
	for(int i=0; i<NUM_LEN; i++) {
		big_int[i] = -1;
	}
	big_int[NUM_LEN-1] = 0;
}

BigInt::~BigInt() {
	delete[] big_int;
}

void BigInt::resetNumber() {
	for(int i=0; i<NUM_LEN; i++) {
		big_int[i] = -1;
	}
	big_int[NUM_LEN-1] = 0;
}

void BigInt::setNumber(long long n) {
	if(n<0) throw "BigInt must be positive";
	else if(n==0) {
		resetNumber();
		return;
	}
	for(int i=NUM_LEN-1; i>=0; i--) {
		if(n!=0) {
			big_int[i] = n % 10;
			n /= 10;
		} else {
			if(big_int[i]==-1) {
				break;
			}
			big_int[i] = -1;
		}
	}
	if(n>0) throw "overflow occured";
}

void BigInt::printNumber() {
	for(int i=0; i<NUM_LEN; i++) {
		if(big_int[i]<0) {
			continue;
		}
		cout << big_int[i];
	}
	cout << endl;
}

void BigInt::multiplyNumber(short n) {
	int carry=0;
	if(n<0) throw "BigInt must be positive";
	else if(n==0) setNumber(0);
	for(int j=NUM_LEN-1; j>=0; j--) {
		if(big_int[j]<0) {
			if(carry>0) {
				big_int[j] = carry%10;
				carry /= 10;
			}
			if(n>0) {
				continue;
			} else {
				break;
			}
		}
		big_int[j] *= n;
		if(carry>0) {
			big_int[j] += carry;
			carry = 0;
		}
		if(big_int[j]>=10) {
			carry = big_int[j] / 10;
			big_int[j] %= 10;
			if(j==0) throw "overflow occured";
		}
	}
}

void BigInt::addNumber(short n) {
	int carry=0;
	if(n<0) throw "input must be positive";
	for(int j=NUM_LEN-1; j>=0; j--) {
		if(big_int[j]<0) {
			big_int[j]++;
		}
		big_int[j] += n%10;
		n /= 10;
		if(carry>0) {
			big_int[j] += carry;
			carry = 0;
		}
		if(big_int[j]>=10) {
			carry = big_int[j] / 10;
			big_int[j] %= 10;
		}
		if(n==0 && carry==0) {
			break;
		} else if(j==0) {
			throw "overflow occured";
		}
	}
}

void BigInt::subtractNumber(short n) {
	int carry=0;
	if(n<0) throw "input must be positive";
	for(int j=NUM_LEN-1; j>=0; j--) {
		if(big_int[j]==-1) throw "BigInt must be positive";
		big_int[j] -= n%10;
		n /= 10;
		if(carry>0) {
			big_int[j] -= carry;
			carry = 0;
		}
		if(big_int[j]<0) {
			carry = big_int[j] / (-10);
			if((big_int[j]%10)!=0) {
				carry++;
				big_int[j] = 10 + big_int[j] % 10;
			} else {
				big_int[j] = 0;
			}
		}
		if(n==0 && carry==0) {
			for(int k=0; k<NUM_LEN; k++) {
				if(big_int[k]==0) {
					big_int[k] = -1;
				} else if(big_int[k]!=-1) {
					break;
				}
			}
			break;
		} else if(j==0) {
			throw "overflow occured";
		}
	}
}
