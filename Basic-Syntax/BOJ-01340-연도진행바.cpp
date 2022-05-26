// BOJ-01340 / 연도 진행바
// devgeon, 2022.05.26, C++17
// https://www.acmicpc.net/problem/1340
 
// 오늘 날짜가 주어졌을 때, 이번 해가 몇 퍼센트 지났는지 출력하는 프로그램을 작성하시오.
// 입력: 첫째 줄에 Month DD, YYYY HH:MM과 같이 주어진다.
//      Month는 현재 월로, January, February, March, April, May, June, July, August, September, October, November, December 중 하나이다.
//      YYYY는 현재 연도로, 1800보다 크거나 같고, 2600보다 작거나 같은 숫자 네자리이다. DD, HH, MM은 모두 2자리 숫자이고, 현재 일, 시, 분이다.
//      항상 올바른 날짜와 시간만 입력으로 주어진다.
// 출력: 첫째 줄에 문제의 정답을 출력한다. 절대/상대 오차는 10^(-9)까지 허용한다.


#include<iostream>
#include<string>
#include<array>

const std::array<int,12> DATE_OF_MONTHS = {31,28,31,30,31,30,31,31,30,31,30,31};
const unsigned long long PRECISION = 10000000000;

int main()
{
	int year=0, month=0, day=0;
	int hour=0, minute=0;
	int day_count=0;
	int minute_count=0;
	int minute_total=0;
	bool leap_year=false;
	unsigned long long percentage_int = 0;
	std::string month_str;
	
	std::cin >> month_str >> day;
	std::cin.ignore(2,',');
	std::cin >> year >> hour;
	std::cin.ignore(2,':');
	std::cin >> minute;
	
	if(month_str=="December") {
		month = 12;
	} else if (month_str=="November") {
		month = 11;
	} else if (month_str=="October") {
		month = 10;
	} else if (month_str=="September") {
		month = 9;
	} else if (month_str=="August") {
		month = 8;
	} else if (month_str=="July") {
		month = 7;
	} else if (month_str=="June") {
		month = 6;
	} else if (month_str=="May") {
		month = 5;
	} else if (month_str=="April") {
		month = 4;
	} else if (month_str=="March") {
		month = 3;
	} else if (month_str=="February") {
		month = 2;
	} else if (month_str=="January") {
		month = 1;
	}
	
	for(int i=month-2; i>=0; i--) {
		day_count += DATE_OF_MONTHS[i];
	}
	if(year%400==0 || (year%4==0 && year%100!=0)) {
		leap_year = true;
		if(month>2) {
			day_count++;
		}
	}
	day_count += day;
	
	minute_count = ((day_count-1)*24*60) + (hour*60) + minute;
	minute_total = ((leap_year?366:365)*24*60);
	percentage_int = ((unsigned long long) minute_count) * PRECISION*100;
	percentage_int = percentage_int / minute_total + (percentage_int%minute_total > minute_total/2 ? 1 : 0);
	
	std::cout << percentage_int/PRECISION << '.' << percentage_int%PRECISION << std::endl;
	
    return 0;
}
