// BOJ-12813 / 이진수 연산
// devgeon, 2024.04.16, C++17
// https://www.acmicpc.net/problem/12813

// 연산자 오버로딩 연습

#include <iostream>

using namespace std;
using BinaryString = string;

BinaryString operator&(const BinaryString &a, const BinaryString &b);
BinaryString operator|(const BinaryString &a, const BinaryString &b);
BinaryString operator^(const BinaryString &a, const BinaryString &b);
BinaryString operator!(const BinaryString &binStr);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BinaryString A, B;
    cin >> A >> B;

    cout << (A & B) << '\n'
         << (A | B) << '\n'
         << (A ^ B) << '\n'
         << !A << '\n'
         << !B << endl;

    return 0;
}

BinaryString operator&(const BinaryString &a, const BinaryString &b) {
    BinaryString result;
    result.reserve(a.size());
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] - '0' & b[i] - '0') + '0';
    }
    return result;
}

BinaryString operator|(const BinaryString &a, const BinaryString &b) {
    BinaryString result;
    result.reserve(a.size());
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] - '0' | b[i] - '0') + '0';
    }
    return result;
}

BinaryString operator^(const BinaryString &a, const BinaryString &b) {
    BinaryString result;
    result.reserve(a.size());
    for (int i = 0; i < a.size(); i++) {
        result += (a[i] - '0' ^ b[i] - '0') + '0';
    }
    return result;
}

BinaryString operator!(const BinaryString &binStr) {
    BinaryString result;
    result.reserve(binStr.size());
    for (char c : binStr) {
        result += (c == '0' ? '1' : '0');
    }
    return result;
}
