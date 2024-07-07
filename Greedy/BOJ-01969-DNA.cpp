// BOJ-01969 / DNA
// devgeon, 2024.07.07, C++17
// https://www.acmicpc.net/problem/1969

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0, len = 0, max = 0, distance = 0;
    string min_dna = "";
    cin >> num >> len;

    vector<string> dna_list(num, "");
    for (string &dna : dna_list) {
        cin >> dna;
    }

    for (int c = 0; c < len; c++) {
        vector<int> counter(26, 0);
        for (int r = 0; r < num; r++) {
            counter[dna_list[r][c] - 'A']++;
        }
        max = 0;
        for (int i = 0; i < 26; i++) {
            if (counter[i] > counter[max]) {
                max = i;
            }
        }
        min_dna.push_back(max + 'A');
        distance += num - counter[max];
    }
    cout << min_dna << '\n' << distance << endl;

    return 0;
}
