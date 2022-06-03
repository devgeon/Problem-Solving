// BOJ-17478 / 재귀함수가 뭔가요?
// devgeon, 2022.06.03, C++17
// https://www.acmicpc.net/problem/17478

// 재귀함수가 무엇인지 물어보는 사람들을 위해 자동 응답 챗봇을 준비하기로 했다.
// 예제를 참고하여 챗봇의 응답을 출력하는 프로그램을 작성하시오.
// 입력: 출력을 원하는 재귀 횟수 N(1 ≤ N ≤ 50)이 주어진다.
// 출력: 출력 예시를 보고 재귀 횟수에 따른 챗봇의 응답을 출력한다.


#include<iostream>
#include<string>

using namespace std;

void recursion(int num, int cur=0);

int main()
{
	int num=0;
	
	cin >> num;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	recursion(num);
	
    return 0;
}

void recursion(int num, int cur)
{
	const string dash = "____";
	string cur_dash = "";
	for(int i=0; i<cur; i++) {
		cur_dash += dash;
	}
	
	cout << cur_dash << "\"재귀함수가 뭔가요?\"\n";
	if(num!=cur) {
		cout << cur_dash << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n"
			 << cur_dash << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n"
			 << cur_dash << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		recursion(num, cur+1);
	} else {
		cout << cur_dash << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	}
	cout << cur_dash << "라고 답변하였지.\n";
}
