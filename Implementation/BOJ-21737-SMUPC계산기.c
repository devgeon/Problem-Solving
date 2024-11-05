// BOJ-21737 / SMUPC 계산기
// devgeon, 2024.11.05, C99
// https://www.acmicpc.net/problem/21737

#include <stdio.h>
#define bool char

int main() {
    char oper = 0;
    bool is_printed = 0;
    int count = 0, num = 0, result = 0;

    scanf("%d\n%d", &count, &result);
    while (count-- && scanf("%c", &oper) != EOF) {
        if (oper == 'C') {
            printf("%d ", result);
            is_printed = 1;
            continue;
        }

        scanf("%d", &num);
        switch (oper) {
        case 'S':
            result -= num;
            break;
        case 'M':
            result *= num;
            break;
        case 'U':
            result /= num;
            break;
        case 'P':
            result += num;
            break;
        default:
            printf("Operation not defined for %c", oper);
        }
    }

    if (!is_printed) {
        printf("NO OUTPUT");
    }

    return 0;
}
