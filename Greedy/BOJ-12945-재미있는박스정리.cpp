// BOJ-12945 / 재미있는 박스 정리
// devgeon, 2023.12.07, C++17
// https://www.acmicpc.net/problem/12945

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_boxes = 0, cleaned = 0;
    cin >> total_boxes;
    int lit = 0, big = 0;
    vector<int> box_size(total_boxes, 0);
    for (int i = 0; i < total_boxes; i++) {
        cin >> box_size[i];
    }
    sort(box_size.begin(), box_size.end());

    for (lit = 0, big = total_boxes / 2;
         lit < total_boxes / 2 && big < total_boxes;) {
        if ((box_size[lit] << 1) <= box_size[big]) {
            cleaned++;
            lit++;
        }
        big++;
    }

    cout << total_boxes - cleaned << endl;

    return 0;
}
