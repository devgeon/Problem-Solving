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

void get_str(deque<char>& deq);
int decompress(const deque<char>& compressed, deque<char>::iterator& start);


int main()
{
    deque<char> compressed;
    int length = 0;

    get_str(compressed);
    deque<char>::iterator begin = compressed.begin();
    length = decompress(compressed, begin);
    cout << length << endl;

    return 0;
}


int decompress(const deque<char>& compressed, deque<char>::iterator& start)
{
    int length = 0;
    int repeat = 0;
    deque<char>::iterator i;

    for(i=start; i<compressed.end(); i++) {
        if(i+1 != compressed.end() && *(i+1)=='(') {
            repeat = *i-'0';
            i += 2;
            length += repeat * decompress(compressed, i);
        } else if(*i==')') {
            break;
        } else {
            length++;
        }
    }
    start = i;
    return length;
}

void get_str(deque<char>& deq)
{
    char c;

    while((c=cin.get()) != '\n' && c != cin.eof()) {
        deq.push_back(c);
    }

    return;
}
