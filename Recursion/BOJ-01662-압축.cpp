// BOJ-01662 / 압축
// devgeon, 2022.08.26, C++17
// https://www.acmicpc.net/problem/1662

// 문자열 S의 부분 문자열을 K(Q)의 형태로 압축할 수 있다고 하자.
// 여기서 K는 한자리 정수, Q는 0자리 이상의 문자열이며, K(Q)는 Q라는 문자열이 K번 반복된다는 의미이다.
// 압축된 문자열이 주어졌을 때, 압축을 해제하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 압축된 문자열 S가 주어진다. S는 최대 50자이며, 소괄호와 0~9 사이의 숫자로만 구성된다.
// 출력: 첫째 줄에 압축이 해제된 문자열의 길이를 출력한다. 이 값은 2,147,473,647 보다 작거나 같다.


#include<iostream>
#include<deque>

using namespace std;

void input_deque(deque<char>& deq);
void repeat_deque(deque<char>& deq, int repeat=1);
void concat_deque(deque<char>& deq1, const deque<char>& deq2);
void print_deque(deque<char>& deq);
deque<char>::iterator decompress(const deque<char>& compressed, deque<char>& decompressed, const deque<char>::iterator& start);


int main()
{
	deque<char> compressed;
    deque<char> decompressed;

    input_deque(compressed);
    decompress(compressed, decompressed, compressed.begin());
    // print_deque(decompressed);
    cout << decompressed.size() << endl;
	
    return 0;
}


deque<char>::iterator decompress(const deque<char>& compressed, deque<char>& decompressed, const deque<char>::iterator& start)
{
    int repeat = 0;
    deque<char>::iterator i;
    deque<char> decompressed_temp;

    for(i=start; i<compressed.end(); i++) {
        if(*i=='(') {
            repeat = decompressed.back()-'0';
            decompressed.pop_back();
            decompressed_temp.clear();
            i = decompress(compressed, decompressed_temp, i+1);
            repeat_deque(decompressed_temp, repeat);
            concat_deque(decompressed, decompressed_temp);
        } else if(*i==')') {
            break;
        } else {
            decompressed.push_back(*i);
        }
    }
    return i;
}

void input_deque(deque<char>& deq)
{
    char c;
    while((c=cin.get()) != '\n' && c != cin.eof()) {
        deq.push_back(c);
    }
    return;
}

void repeat_deque(deque<char>& deq, int repeat)
{
    if(repeat==0) {
        deq.clear();
        return;
    } else if(repeat==1) {
        return;
    } else if(deq.size()==0) {
        return;
    }
    deque<char> deq_temp(deq);
    for(int i=0; i<repeat-1; i++) {
        deq.insert(deq.end(), deq_temp.begin(), deq_temp.end());
    }
    return;
}

void concat_deque(deque<char>& deq1, const deque<char>& deq2)
{
    deq1.insert(deq1.end(), deq2.begin(), deq2.end());
    return;
}

void print_deque(deque<char>& deq)
{
    for(int i=0; i<deq.size(); i++) {
        cout << deq[i];
    }
    cout << endl;
    return;
}
