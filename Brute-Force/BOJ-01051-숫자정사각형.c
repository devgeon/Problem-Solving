// BOJ-01051 / 숫자 정사각형
// devgeon, 2022.05.04, C99
// https://www.acmicpc.net/problem/1051
 
// N×M크기의 직사각형이 있다. 각 칸에는 한 자리 숫자가 적혀 있다.
// 이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오.
// 이때, 정사각형은 행 또는 열에 평행해야 한다.

// 입력: 첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 수가 주어진다.

// 출력: 첫째 줄에 정답 정사각형의 크기를 출력한다.


#include<stdio.h>
#include<stdlib.h>


int main()
{
    char width=0, height=0;
	char **rectangle=0;
	char sqrLen=0;
	
	scanf("%hhd %hhd", &height, &width);
	sqrLen = ((width>height) ? height : width) - 1;
	
	if((rectangle = (char **) calloc(height, sizeof(char *))) == NULL) {
		return -1;
	}
	for(char i=0; i<height; i++) {
		if((rectangle[i] = (char *) calloc(width, sizeof(char))) == NULL) {
			return -1;
		}
	}
	
	for(char i=0; i<height; i++) {
		for(char j=0; j<width; j++) {
			do {
				scanf("%c", &rectangle[i][j]);
			} while(rectangle[i][j]<'0' || rectangle[i][j]>'9');
		}
	}
	
	for( ; sqrLen>0; sqrLen--) {
		for(char row=0; row+sqrLen<height; row++) {
			for(char col=0; col+sqrLen<width; col++) {
				if(rectangle[row][col] == rectangle[row+sqrLen][col]
				  && rectangle[row][col] == rectangle[row][col+sqrLen]
				  && rectangle[row][col] == rectangle[row+sqrLen][col+sqrLen]) {
					printf("%hd\n", (short)(sqrLen+1)*(short)(sqrLen+1));
					free(rectangle);
					return 0;
				}
			}
		}
	}
	
	printf("%hd\n", 1);
	free(rectangle);
    return 0;
}
