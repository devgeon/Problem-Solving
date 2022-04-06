// BOJ-14681 / 사분면 고르기
// devgeon, 2022.04.06, C99
// https://www.acmicpc.net/problem/14681
 
// 점의 좌표를 입력받아 그 점이 어느 사분면에 속하는지 알아내는 프로그램을 작성하시오.
// 참고: https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14681/1.png
// 입력: 첫 줄에는 정수 x (−1000 ≤ x ≤ 1000; x ≠ 0)가 주어지고,
//      다음 줄에는 정수 y (−1000 ≤ y ≤ 1000; y ≠ 0)가 주어진다.
// 출력: 점 (x, y)의 사분면 번호(1, 2, 3, 4 중 하나)를 출력한다.

#include<stdio.h>

int main()
{
	int x=0, y=0, quadrant=0;
	
	scanf("%d %d", &x, &y);
	
	if(x>0) {
		if(y>0) {
			quadrant = 1;
		} else {
			quadrant = 4;
		}
	} else {
		if(y>0) {
			quadrant = 2;
		} else {
			quadrant = 3;
		}
	}
	
	printf("%d", quadrant);
	
    return 0;
}
