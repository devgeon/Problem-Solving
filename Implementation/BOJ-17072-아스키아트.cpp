// BOJ-17072 / 아스키 아트
// devgeon, 2024.04.02, C++17
// https://www.acmicpc.net/problem/17072

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char pixel = '\0';
    int row = 0, col = 0;
    int red = 0, green = 0, blue = 0, grayscale = 0;

    cin >> row >> col;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> red >> green >> blue;

            grayscale = 2126 * red + 7152 * green + 722 * blue;
            if (grayscale < 510'000) {
                pixel = '#';
            } else if (grayscale < 1'020'000) {
                pixel = 'o';
            } else if (grayscale < 1'530'000) {
                pixel = '+';
            } else if (grayscale < 2'040'000) {
                pixel = '-';
            } else {
                pixel = '.';
            }
            cout << pixel;
        }
        cout << '\n';
    }

    return 0;
}
