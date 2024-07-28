// BOJ-26001 / Jagged Skyline
// devgeon, 2024.07.28, C++17
// https://www.acmicpc.net/problem/26001

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool ask(long long col, long long row);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long width = 0, height = 0, top = 0, top_pos = 1;
    cin >> width >> height;
    vector<int> indexes(width, 0);
    for (int i = 0; i < width; i++) {
        indexes[i] = i + 1;
    }
    random_device random_device;
    shuffle(indexes.begin(), indexes.end(),
            default_random_engine(random_device()));

    for (long long i = 0, col = 0, head = 0, tail = 0, mid = 0;
         i < width && top != height; i++) {
        col = indexes[i], head = height, tail = top;
        if (ask(col, tail + 1)) {
            continue;
        }
        while (head > tail) {
            mid = (head + tail) / 2;
            if (ask(col, mid + 1)) {
                head = mid;
            } else {
                tail = mid + 1;
            }
        }
        if (head > top) {
            top = head, top_pos = col;
        }
    }
    cout << "! " << top_pos << ' ' << top << endl;

    return 0;
}

bool ask(long long col, long long row) {
    string response = "";
    cout << "? " << col << ' ' << row << endl;
    cin >> response;
    return (response == "sky");
}
