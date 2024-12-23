// BOJ-15482 / 한글 LCS
// devgeon, 2024.12.23, C++17
// https://www.acmicpc.net/problem/15482

#include <iostream>
#include <vector>

using namespace std;

class UTF8String : public string {
  private:
    const int CHAR_LEN = 3;

  public:
    UTF8String(const char *str) : string(str) {}

    inline int size() {
        return string::size() / CHAR_LEN;
    }

    inline string operator[](const int idx) const {
        return substr(idx * CHAR_LEN, CHAR_LEN);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    UTF8String str1 = "", str2 = "";
    cin >> str1 >> str2;

    vector<vector<int>> cache(2, vector<int>(str2.size() + 1, 0));
    for (int s1 = 0, end1 = str1.size(); s1 < end1; s1++) {
        for (int s2 = 0, end2 = str2.size(); s2 < end2; s2++) {
            cache[(s1 + 1) & 1][s2 + 1] =
                (str1[s1] == str2[s2] ? cache[s1 & 1][s2] + 1
                : max(cache[(s1 + 1) & 1][s2], cache[s1 & 1][s2 + 1]));
        }
    }
    cout << cache[(str1.size()) & 1][str2.size()] << endl;

    return 0;
}
