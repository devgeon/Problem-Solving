// BOJ-01003 / 피보나치 함수
// devgeon, 2024.09.22, C99
// https://www.acmicpc.net/problem/1003

#include <stdio.h>
#define MAX 40

typedef struct _Counter {
    int zero;
    int one;
} Counter;

int main() {
    int cases = 0, num = 0;
    Counter counter[MAX + 1];

    scanf("%d", &cases);

    counter[0].zero = 1, counter[0].one = 0;
    counter[1].zero = 0, counter[1].one = 1;

    for (int i = 2; i <= MAX; i++) {
        counter[i].zero = counter[i - 1].zero + counter[i - 2].zero;
        counter[i].one = counter[i - 1].one + counter[i - 2].one;
    }

    for (int i = 0; i < cases; i++) {
        scanf("%d", &num);
        printf("%d %d\n", counter[num].zero, counter[num].one);
    }

    return 0;
}
